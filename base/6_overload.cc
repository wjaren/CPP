#include <iostream>

/**
 * 重载是 C++ 的一个特性，允许你定义多个同名函数，
 * 但参数类型或参数个数不同。
 * 编译器会根据调用时传入的实参，
 * 决定最终匹配并调用哪个函数。
 */

int add(int a, int b) { return a + b; }

double add(double a, double b) { return a + b; }

/**
 * C++23 引入了“auto 函数形参”特性，
 * 允许在函数声明中使用 auto 作为参数类型。
 * 编译器会根据实参自动推导参数类型。
 * 这对编写泛型函数很有帮助，
 * 可以减少为不同类型重复编写重载的工作。
 */

auto add(auto a, auto b) { return a + b; }

void print() { std::cout << "print() called" << std::endl; }

void print(int x) { std::cout << "print(int) called with " << x << std::endl; }

void print(double x) {
    std::cout << "print(double) called with " << x << std::endl;
}

void default_print(int a = 0, int b = 0) {
    std::cout << "default_print(int, int) called with " << a << " and " << b
              << std::endl;
}

/**
 * 这会导致编译错误，因为默认参数应在函数声明处给出，
 * 而不是在函数定义处给出。
 * 否则当只传一个参数调用时，编译器无法确定第二个参数的默认值。
 */
// void default_print(int a = 0, int b) {
//     std::cout << "default_print(int, int) called with " << a << " and " << b
//               << std::endl;
// }

extern "C" {
// 这个函数可以被 C 代码调用
int add_c(int a, int b) { return a + b; }
// int add_c(double a, double b) { return a + b; }
// 若再定义同名重载，会破坏 C 链接规则并导致链接错误
}

int main() {
    std::cout << "1 + 2 = " << add(1, 2)
              << std::endl; // 调用 add(int, int)，返回类型为 int
    std::cout << "1.5 + 2.5 = " << add(1.5, 2.5)
              << std::endl; // 调用 add(double, double)，返回类型为 double

    print();     // 调用 print()，无参数
    print(42);   // 调用 print(int)，参数为 int
    print(3.14); // 调用 print(double)，参数为 double

    default_print();      // 使用默认参数调用 default_print(int, int)
    default_print(5);     // 调用 default_print(int, int)，a = 5
    default_print(5, 10); // 调用 default_print(int, int)，a = 5, b = 10

    return 0;
}