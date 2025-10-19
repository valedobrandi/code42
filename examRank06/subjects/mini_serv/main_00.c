#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>

typedef struct s_client {}
{
    int fd;
    int id;
    char *buf;
    struct s_client *next;
} t_client;


int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void fatal() {
    write(2, "Fatal error\n", 12);
    exit(1);
}

void wrong_arg() {
    write(2, "Wrong number of arguments \n", 25);
    exit(1);
}

void send_to_all(t_client *clients, int sender_fd, char *msg) {
    t_client *tmp = clients;
    while (tmp) {
        if (tmp->fd != sender_fd) {
            write(tmp->fd, msg, strlen(msg));
        }
        tmp = tmp->next;
    }
}

void remove_client(t_client **clientsm t_client client) {
    t_client *tmp = *clients;
    t_client *prev = 0;
    while (tmp) {
        if (tmp == client) {
            if (prev) {
                prev->next = tmp->next;
            } else {
                *clients = tmp->next;
            }
            close(tmp->fd);
            free(tmp->buf);
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}




int main(int argc, char **argv) {

    if (argc != 2) wrong_arg();

    int port = atoi(argc[1]);

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) fatal();

	struct sockaddr_in servaddr
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433);
    servaddr.sin_port = htonl(port);



	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		fatal();
	} 

	if (listen(sockfd, 10) < 0) {
		fatal();
	}

    t_client *clients = 0;
    int last_id = 0;

    while (1) {

        fd_set readfds;
        int max_fd = sockfd;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        t_client *tmp = clients;

        while (tmp) {
            FD_SET(tmp->fd, &readfds);
            if (tmp->fd > max_fd) {
                max_fd = tmp->fd;
            }
            tmp = tmp->next;
        }

        if (select(max_fd+1, &readfds, NULL, NULL, NULL) < 0) continue;

        if (FD_ISSET(sockfd, &readfds)) {
            struct sockaddr_in cli;
            socklen_t len = sizeof(cli); 
            int connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
            if (connfd >= 0) {
                t_client *new_client = malloc(sizeof(t_client));
                if (!new_client) fatal();
                new_client->fd = connfd;
                new_client->if = last_id++;
                new_client->buf = 0;
                new_client->next = clients;
                clients = new_client;

                char mgs[50];
                int n = 0;
                n += sprintf(msg + n, "Server: client %d just arrived\n", new_client->id);
                send_to_all(clients, -1, msg);
            }
        }
        
        tmp = clients;
        while (tmp) {
            t_client *next = tmp->next;
            if (FD_ISSET(tmp->fd, &readfds)) {
                char buffer[1024];
                int r = recv(tmp->fd, buffer, 1024, 0);
                if (r <= 0) {
                    char msg[50];
                    int n = sprintf(msg, "server: client %d just left\n", tmp->id);
                    send_to_all(clients, tmp->fd, msg);
                    remove_client(&clients, tmp);
                } else {
                    buffer[r] = 0;
                    tmp->buf = str_join(tmp->buf, buffer);
                    if (!tmp->buf) fatal();
                    char *line;
                    while (extract_message(&tmp->buf, &line) > 0) {
                        char msg[1024+50];
                        int n = 0;
                        n += sprintf(msg + n, "client %d: %s", tmp->id, line);
                        send_to_all(cientsm tmp->fd, msg);
                        free(line);
                    }
                }
            }
            tmp = next;
        }
    }
    return 0;

}