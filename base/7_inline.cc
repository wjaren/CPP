#include <iostream>

#define MAX(a, b) (a) > (b) ? (a) : (b)
// #define MAX(a, b) ((a) > (b) ? (a) : (b))
// 这一版更安全，因为把整个表达式也包起来了。

/**
 * inline 的本意是建议编译器“可以考虑内联展开”。
 * 现代编译器会自己决定是否真的展开，所以它不等于“必须展开”。
 *
 * 相比宏，inline 函数有类型检查，通常更安全。
 */
inline int max(int a, int b) { return a > b ? a : b; }

int main() {
    int a = MAX(10, 5) + 1;
    std::cout << "The maximum value is: " << a
              << std::endl; // 结果可能不是你直觉里的 11。

    int b = max(10, 5) + 1;
    std::cout << "The maximum value is: " << b
              << std::endl; // inline 函数按正常函数表达式求值，结果是 11。
    return 0;
}
