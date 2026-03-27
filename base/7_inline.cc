#include <iostream>

#define MAX(a, b) (a) > (b) ? (a) : (b)
// #define MAX(a, b) ((a) > (b) ? (a) : (b))
// 这是更安全的宏写法

/**
 * inline 函数是 C++ 的一个特性，编译器可将函数调用
 * 直接替换为函数体代码，从而减少调用开销。
 * 但也要谨慎使用：过度内联可能导致代码膨胀，且不一定总能带来性能提升。
 */
inline int max(int a, int b) { return a > b ? a : b; }

int main() {
    int a = MAX(10, 5) + 1;                                  // 会展开为 (10) > (5) ? (10) : (5) + 1
    std::cout << "The maximum value is: " << a << std::endl; // 结果为 10

    int b = max(10, 5) + 1;                                  // 会调用 inline 函数 max
    std::cout << "The maximum value is: " << b << std::endl; // 结果为 11
    return 0;
}