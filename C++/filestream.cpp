#include <iostream>
#include <fstream>

int main( void ) {

    std::ifstream ifs("numbers");
    unsigned int dst;
    unsigned int dst2;
    std::string str;
    ifs >> dst >> dst2 >> str;

    std::cout << dst << " " << dst2 << " " << str << std::endl;
    ifs.close();

    std::ofstream ofs("test.out");

    ofs << "i like ponies" << std::endl;
    ofs.close();

    return 0;
}