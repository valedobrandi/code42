#include <sys/types.h>
#include <sys/socket.h>
#include <poll.h>
#include <vector>
#include <algorithm>
#include <netdb.h>
#include <cstdio>
#include <string.h>
#include <unistd.h>

#define PORT "19456"
#define BACKLOG 10

using namespace std;

int main() {

    sockaddr_storage remote_addr;
    socklen_t remote_addr_size;
    addrinfo settings, *result_info, *info;
    int srv_socket, conn_socket, gai_result, send_status, fd_index, fds_num, yes = 1;
    vector <pollfd> fds;
    pollfd listener_fd, new_fd;

    memset(&settings, 0, sizeof settings);
    settings.ai_family = AF_INET;
    settings.ai_socktype = SOCK_STREAM;
    settings.ai_flags = AI_PASSIVE;

    if((gai_result = getaddrinfo(NULL, PORT, &settings, &result_info)) != 0) {
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(gai_result));
            return 1;
    }

    for(info = result_info; info != NULL; info = info->ai_next) {
            if((srv_socket = socket(info->ai_family, info->ai_socktype, info->ai_protocol)) == -1) {
                    perror("Error on socket()");
                    continue;
            }

            if(setsockopt(srv_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
                    close(srv_socket);
                    perror("Error on setsockopt()");
                    return 1;
            }

            if(bind(srv_socket, info->ai_addr, info->ai_addrlen) == -1) {
                    close(srv_socket);
                    perror("Error on bind()");
                    continue;
            }

            break;
    }

    if(info == NULL) {
            fprintf(stderr, "Failed on all bind()");
            return 1;
    }

    freeaddrinfo(result_info);

    if(listen(srv_socket, BACKLOG) == -1) {
            perror("Error on listen()");
            return 1;
    }

    listener_fd.fd = srv_socket;
    listener_fd.events = POLLIN;
    fds.push_back(listener_fd);

    while(1) {

            pollfd fds_array[fds.size()];
            copy(fds.begin(), fds.end(), fds_array);

            poll(fds_array, (nfds_t) fds.size(), 0);

            if(fds_array[0].revents & POLLIN) {
                    remote_addr_size = sizeof remote_addr;

                    if((conn_socket = accept(srv_socket, (sockaddr *) &remote_addr, &remote_addr_size)) == -1) {
                            close(srv_socket);
                            perror("Error on accept()");
                            return 1;
                    }

                    new_fd.fd = conn_socket;
                    new_fd.events = POLLOUT;
                    fds.push_back(new_fd);
            }

            for(fd_index = 1, fds_num = fds.size(); fd_index < fds_num; fd_index++) {
                    if(fds_array[fd_index].revents & POLLOUT) {
                            send_status = send(fds_array[fd_index].fd, "Test", 4, 0);
                            close(fds_array[fd_index].fd);
                            fds.erase(fds.begin() + fd_index);
                            if(send_status == -1) {
                                    perror("Error on send()");
                                    return 1;
                            }

                    }
            }
    }

    return 0;

}