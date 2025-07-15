#include <iostream>
#include <fstream>

std::string addReplaceToFileName(const std::string& filename) {
    size_t lastDot = filename.find_last_of('.');
    if ( lastDot == std::string::npos) return filename + ".replace";
    return filename.substr(0, lastDot) + ".replace" + filename.substr(lastDot);
}

void replace_all( std::fstream& read_file , std::fstream& write_file, const char *to_find, const char *to_replace) {
    std::string line;
    while (std::getline(read_file, line)) {
        size_t next = 0;
        std::string find = to_find;
        std::string replace = to_replace;
        while ((next = line.find(find, next)) != std::string::npos)
        {
            line.erase(next, find.length());
            line.insert(next, replace);
            next += replace.length();
        }
        write_file << line << std::endl;;
    }
    return ;
}

int main(int ac, char **av) {
    
    if (ac == 4) {

        std::fstream read_file(av[1], std::ios::in);
        if (!read_file.is_open()) {
            std::cerr << "Failed to open." << std::endl;
            return 1;
        } 

        std::string file_name = addReplaceToFileName(av[1]);

        std::fstream write_file(file_name.c_str(), std::ios::out | std::ios::trunc);
        if (!write_file.is_open()) {
            std::cerr << "Failed to write." << std::endl; 
            read_file.close();
            return 1;
        } 

        replace_all(read_file, write_file, av[2], av[3]);
        read_file.close();
        write_file.close();
    }
    else {
        std::cout << "./main <filename> <search> <replace>" << std::endl;
    }

    return (0);
}