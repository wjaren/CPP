#include <iostream>

int main() {
    // C 风格强制转换写法短，但含义不够明确，也更容易写出危险代码。
    double c_d = 3.14;
    int c_i = (int)c_d; // 小数部分会被截掉。
    std::cout << "c_d: " << c_d << ", c_i: " << c_i << std::endl;

    int *c_p = (int *)&c_d;
    std::cout << "c_p: " << c_p << ", *c_p: " << *c_p
              << std::endl; // 这是把 double 的内存按 int 去解释，属于危险操作。

    // C++ 风格转换更推荐，因为“想做什么”写得更清楚。
    double cpp_d = 3.14;
    int cpp_i = static_cast<int>(cpp_d);
    std::cout << "cpp_d: " << cpp_d << ", cpp_i: " << cpp_i << std::endl;

    // int *cpp_p = static_cast<int *>(&cpp_d);
    // 错误：static_cast 不允许把 double* 直接转成 int*。

    int num = 1;
    const int *p = &num;
    int *q = const_cast<int *>(p); // 去掉 const 限定。
    *q = 2;
    std::cout << "num: " << num << ", *p: " << *p << std::endl;

    const int &ref = num;
    int &ref2 = const_cast<int &>(ref);
    ref2 = 3;
    std::cout << "num: " << num << ", ref: " << ref << std::endl;

    return 0;
}
