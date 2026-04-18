#include <iostream>

// 引用本质上是“变量的别名”，不会复制一份新数据。
void test_swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int x = 10;

    int &lref = x; // 左值引用 lref 现在就是 x 的另一个名字。
    std::cout << "lref: " << lref << std::endl;

    lref = 20; // 改 lref，其实就是在改 x。
    std::cout << "x: " << x << std::endl;

    lref = x; // 不是“重新绑定”，只是把 x 的值赋给自己。
    std::cout << "x: " << x << std::endl;

    int *p = &x;
    std::cout << "&p: " << &p << ", p: " << p << ", *p: " << *p << std::endl;
    std::cout << "&lref: " << &lref
              << std::endl; // 引用和被引用对象地址相同。

    int a = 1, b = 2;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    test_swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    const int &ref = x; // const 引用只能读，不能通过它修改值。
    std::cout << "ref: " << ref << std::endl;
    // ref = 30; // 错误

    // 右值引用通常绑定临时对象，常见于移动语义。
    // int &&rref = 30;
    // std::cout << "rref: " << rref << std::endl;
    // rref = 40;

    return 0;
}
