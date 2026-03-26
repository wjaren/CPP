#include <iostream>

int main(int argc, char *argv[]) {

    std::cout << "Number of arguments: " << argc << std::endl;
    std::cout << "Program name: " << argv[0] << std::endl;

    if (argc > 1) {
        std::cout << "Arguments passed to the program:" << std::endl;
        for (int i = 1; i < argc; ++i) {
            std::cout << "Argument " << i << ": " << argv[i] << std::endl;
        }
    } else {
        std::cout << "No arguments passed to the program." << std::endl;
    }

    return 0;
}