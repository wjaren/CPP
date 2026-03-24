#include <iostream>

int g_num = 5;

void func() {}

int main() {
    int l_num1 = 1;
    int l_num2 = 2;

    // stack memory: local variables, address downwards
    std::cout << "&l_num1: " << &l_num1 << ", l_num1: " << l_num1 << std::endl;
    std::cout << "&l_num2: " << &l_num2 << ", l_num2: " << l_num2 << std::endl;

    int *p_num1 = new int(3);
    int *p_num2 = new int(4);

    // heap memory: dynamic variables, address upwards
    std::cout << "&p_num1: " << &p_num1 << ", p_num1: " << p_num1
              << ", *p_num1: " << *p_num1 << std::endl;
    std::cout << "&p_num2: " << &p_num2 << ", p_num2: " << p_num2
              << ", *p_num2: " << *p_num2 << std::endl;

    static int s_num = 6;
    // static memory: static variables, address upwards
    std::cout << "&g_num: " << &g_num << ", g_num: " << g_num << std::endl;
    std::cout << "&s_num: " << &s_num << ", s_num: " << s_num << std::endl;

    // constant word memory: string literals, address upwards
    std::cout << "&Hello, World!: " << &"Hello, World!" << std::endl;

    void *p_func = (void *)&func;
    // code memory: functions, address upwards
    std::cout << "&p_func: " << &p_func << ", p_func: " << p_func << std::endl;

    delete p_num1;
    delete p_num2;

    return 0;
}