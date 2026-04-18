#include <iostream>

int main(int argc, char *argv[]) {
    // argc 表示命令行参数个数，注意程序名本身也算 1 个参数。
    std::cout << "Number of arguments: " << argc << std::endl;

    // argv 是一个字符指针数组，argv[0] 通常是程序名或程序路径。
    std::cout << "Program name: " << argv[0] << std::endl;

    if (argc > 1) {
        // 从 argv[1] 开始，才是用户真正传入的参数。
        std::cout << "Arguments passed to the program:" << std::endl;
        for (int i = 1; i < argc; ++i) {
            std::cout << "Argument " << i << ": " << argv[i] << std::endl;
        }
    } else {
        std::cout << "No arguments passed to the program." << std::endl;
    }

    return 0;
}
