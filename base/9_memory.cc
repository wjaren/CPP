#include <iostream>

int g_num = 5;

void func() {}

int main() {
    int l_num1 = 1;
    int l_num2 = 2;

    // 栈区内存：局部变量，地址通常向下增长
    std::cout << "&l_num1: " << &l_num1 << ", l_num1: " << l_num1 << std::endl;
    std::cout << "&l_num2: " << &l_num2 << ", l_num2: " << l_num2 << std::endl;

    int *p_num1 = new int(3);
    int *p_num2 = new int(4);

    // 堆区内存：动态分配变量，地址通常向上增长
    std::cout << "&p_num1: " << &p_num1 << ", p_num1: " << p_num1
              << ", *p_num1: " << *p_num1 << std::endl;
    std::cout << "&p_num2: " << &p_num2 << ", p_num2: " << p_num2
              << ", *p_num2: " << *p_num2 << std::endl;

    static int s_num = 6;
    // 静态存储区：静态变量，地址通常向上增长
    std::cout << "&g_num: " << &g_num << ", g_num: " << g_num << std::endl;
    std::cout << "&s_num: " << &s_num << ", s_num: " << s_num << std::endl;

    // 常量区：字符串字面量，地址通常向上增长
    std::cout << "&Hello, World!: " << &"Hello, World!" << std::endl;

    void *p_func = (void *)&func;
    // 代码区：函数指令，地址通常向上增长
    std::cout << "&p_func: " << &p_func << ", p_func: " << p_func << std::endl;

    delete p_num1;
    delete p_num2;

    return 0;
}