#include <cstdlib>
#include <iostream>

int main() {
    // C 风格内存管理：malloc 只负责分配字节，不会调用构造函数。
    int *c_p = (int *)malloc(sizeof(int));
    *c_p = 10;
    printf("%d\n", *c_p);
    free(c_p);
    c_p = NULL;

    // C++ 风格内存管理：new/delete 更符合对象模型。
    int *p = new int();           // 值初始化，int 会被初始化为 0。
    std::cout << *p << std::endl;
    *p = 1;
    std::cout << *p << std::endl;
    delete p;
    // std::cout << *p << std::endl; // 危险：delete 之后再访问是未定义行为。
    p = nullptr; // 置空是个好习惯，能减少误用悬空指针的风险。

    // 直接给动态变量一个初始值。
    int *p1 = new int(10);
    std::cout << *p1 << std::endl;
    delete p1;

    // 使用花括号进行值初始化。
    int *p2 = new int{};
    std::cout << *p2 << std::endl;
    delete p2;

    int *p3 = new int{20};
    std::cout << *p3 << std::endl;
    delete p3;

    // 动态数组需要用 delete[] 释放。
    int *arr_ptr = new int[3]();
    std::cout << sizeof(arr_ptr)
              << std::endl; // 这里得到的是指针大小，不是数组总字节数。
    for (int i = 0; i < 3; ++i) {
        std::cout << arr_ptr[i] << std::endl;
    }
    delete[] arr_ptr;

    int *arr_ptr2 = new int[3]{1, 2, 3};
    for (int i = 0; i < 3; ++i) {
        std::cout << arr_ptr2[i] << std::endl;
    }
    delete[] arr_ptr2;

    return 0;
}
