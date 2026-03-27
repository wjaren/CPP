#include <cstdlib>
#include <iostream>

int main() {
    // C 风格内存管理
    int *c_p = (int *)malloc(sizeof(int)); // 类型转换：void* 转为 int*
    *c_p = 10;
    printf("%d\n", *c_p);
    free(c_p); // 释放 malloc 分配的内存
    c_p = NULL;

    // C++ 风格内存管理
    int *p = new int();           // 初始化为 0
    std::cout << *p << std::endl; // 默认初始化为 0
    *p = 1;
    std::cout << *p << std::endl; // 值为 1
    delete p;                     // 释放 new 分配的内存
    std::cout << *p << std::endl; // 未定义行为，p 此时为悬空指针
    p = nullptr;                  // 将 p 置空，避免继续误用悬空指针

    // 使用圆括号进行值初始化
    int *p1 = new int(10); // 初始化为 10
    std::cout << *p1 << std::endl;
    delete p1;

    // 使用空花括号进行值初始化
    int *p2 = new int{}; // 值初始化为 0
    std::cout << *p2 << std::endl;
    delete p2;

    // 使用花括号和给定值进行初始化
    int *p3 = new int{20}; // 值初始化为 20
    std::cout << *p3 << std::endl;
    delete p3;

    int *arr_ptr = new int[3]();               // 分配 3 个 int 的数组
    std::cout << sizeof(arr_ptr) << std::endl; // 这里是指针大小，不是数组总大小
    for (int i = 0; i < 3; ++i) {
        std::cout << arr_ptr[i] << std::endl;
    }
    delete[] arr_ptr; // 释放数组

    int *arr_ptr2 = new int[3]{1, 2, 3}; // 用给定值初始化 3 个 int 的数组
    for (int i = 0; i < 3; ++i) {
        std::cout << arr_ptr2[i] << std::endl;
    }
    delete[] arr_ptr2; // 释放数组

    return 0;
}