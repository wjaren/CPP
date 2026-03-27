#include <iostream>

int main(int argc, char *argv[]) {

    std::cout << "Number of arguments: " << argc << std::endl; // argc 包含程序名这个第一个参数
    std::cout << "Program name: " << argv[0] << std::endl;     // argv[0] 是程序名

    if (argc > 1) {
        // 遍历参数并打印
        std::cout << "Arguments passed to the program:" << std::endl;
        for (int i = 1; i < argc; ++i) {
            std::cout << "Argument " << i << ": " << argv[i] << std::endl;
        }
    } else {
        std::cout << "No arguments passed to the program." << std::endl;
    }

    return 0;
}