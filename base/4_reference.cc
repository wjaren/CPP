#include <iostream>

// 不拷贝值，而是通过引用直接修改原变量
void test_swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int x = 10;
    int &lref = x;                              // x 的左值引用
    std::cout << "lref: " << lref << std::endl; // 输出：10
    lref = 20;                                  // 通过 lref 修改 x
    std::cout << "x: " << x << std::endl;       // 输出：20
    lref = x;                                   // 通过 lref 给自身赋值，无变化
    std::cout << "x: " << x << std::endl;       // 输出：20

    int *p = &x; // 指向 x 的指针
    std::cout << "&p: " << &p << ", p: " << p << ", *p: " << *p
              << std::endl; // 输出：x 的地址、x 的值（20）
    std::cout << "&lref: " << &lref
              << std::endl; // 输出：x 的地址（与 p 相同）

    int a = 1, b = 2;
    std::cout << "Before swap: a = " << a << ", b = " << b
              << std::endl; // 输出：a = 1, b = 2
    test_swap(a, b);        // 使用引用交换 a 和 b
    std::cout << "After swap: a = " << a << ", b = " << b
              << std::endl; // 输出：a = 2, b = 1

    const int &ref = x;                       // x 的 const 引用
    std::cout << "ref: " << ref << std::endl; // 输出：20
    // ref = 30; // 错误：不能修改 const 引用

    // int &&rref = 30; // 绑定到临时量的右值引用
    // std::cout << "rref: " << rref << std::endl; // 输出：30
    // rref = 40; // 通过 rref 修改该临时量
    // std::cout << "rref: " << rref << std::endl; // 输出：40

    return 0;
}