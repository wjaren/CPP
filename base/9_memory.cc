#include <iostream>

int g_num = 5;

void func() {}

int main() {
    int l_num1 = 1;
    int l_num2 = 2;

    // 栈区：局部变量通常放在这里，函数结束后自动释放。
    std::cout << "&l_num1: " << &l_num1 << ", l_num1: " << l_num1 << std::endl;
    std::cout << "&l_num2: " << &l_num2 << ", l_num2: " << l_num2 << std::endl;

    int *p_num1 = new int(3);
    int *p_num2 = new int(4);

    // 堆区：通过 new / delete 手动管理的内存。
    std::cout << "&p_num1: " << &p_num1 << ", p_num1: " << p_num1
              << ", *p_num1: " << *p_num1 << std::endl;
    std::cout << "&p_num2: " << &p_num2 << ", p_num2: " << p_num2
              << ", *p_num2: " << *p_num2 << std::endl;

    static int s_num = 6;
    // 全局变量和 static 变量一般位于静态存储区。
    std::cout << "&g_num: " << &g_num << ", g_num: " << g_num << std::endl;
    std::cout << "&s_num: " << &s_num << ", s_num: " << s_num << std::endl;

    // 字符串字面量通常存放在只读常量区。
    std::cout << "&Hello, World!: " << &"Hello, World!" << std::endl;

    void *p_func = (void *)&func;
    // 函数本身的指令也会放在程序的代码区。
    std::cout << "&p_func: " << &p_func << ", p_func: " << p_func << std::endl;

    delete p_num1;
    delete p_num2;

    return 0;
}
