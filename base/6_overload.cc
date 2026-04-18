#include <iostream>

/**
 * 函数重载的核心规则很简单：
 * 1. 函数名可以相同。
 * 2. 参数列表必须不同，比如参数个数不同、类型不同、顺序不同。
 * 3. 不能只靠返回值类型来区分函数。
 */

int add(int a, int b) { return a + b; }

double add(double a, double b) { return a + b; }

/**
 * 这里的 auto 形参本质上更像“简写版模板函数”。
 * 它能让我们少写很多重复的重载版本。
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
 * 默认参数要从右往左连续提供。
 * 所以下面的写法会报错，因为 b 没有默认值，但 a 却有。
 */
// void default_print(int a = 0, int b) {
//     std::cout << "default_print(int, int) called with " << a << " and " << b
//               << std::endl;
// }

extern "C" {
// extern "C" 用来告诉编译器：按 C 的链接方式导出名字。
// 这通常用于和 C 代码交互。
int add_c(int a, int b) { return a + b; }
// int add_c(double a, double b) { return a + b; }
// 这里不能再做重载，因为 C 链接不支持函数重名区分。
}

int main() {
    std::cout << "1 + 2 = " << add(1, 2) << std::endl;
    std::cout << "1.5 + 2.5 = " << add(1.5, 2.5) << std::endl;

    print();
    print(42);
    print(3.14);

    default_print();
    default_print(5);
    default_print(5, 10);

    return 0;
}
