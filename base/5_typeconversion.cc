#include <iostream>

int main() {

    // C 风格强制转换
    double c_d = 3.14;
    int c_i = (int)c_d; // 从 double 隐式转换到 int，c_i 变为 3
    std::cout << "c_d: " << c_d << ", c_i: " << c_i
              << std::endl; // 输出：c_d: 3.14, c_i: 3
    int *c_p = (int *)&c_d; // 重解释转换：将 c_d 的位模式当成
                            // int 指针来解释
    std::cout << "c_p: " << c_p << ", *c_p: " << *c_p
              << std::endl; // 输出：c_p 为 c_d 地址，*c_p 为某个整数值
                            // （未定义行为）

    // C++ 风格转换
    // static_cast
    double cpp_d = 3.14;
    int cpp_i = static_cast<int>(cpp_d); // static_cast：将 double 转为 int
    std::cout << "cpp_d: " << cpp_d << ", cpp_i: " << cpp_i
              << std::endl; // 输出：cpp_d: 3.14, cpp_i: 3

    // static_cast 不能把 cpp_d 的地址当作 int 指针
    // int *cpp_p = static_cast<int *>(&cpp_d);
    // 错误：不能从 double* 进行 static_cast 到 int*

    // const_cast
    int num = 1;
    const int *p = &num; // 指向 const int 的指针
    // *p = 2; // 错误：不能通过 p 修改 const int
    int *q = const_cast<int *>(p); // 去掉 const 限定，q 指向 num
    *q = 2;                        // 通过 q 修改 num
    std::cout << "num: " << num << ", *p: " << *p
              << std::endl; // 输出：num: 2, *p: 2
    const int &ref = num;   // const int 引用
    // ref = 3; // 错误：不能通过 ref 修改 const int
    // 去掉 const 限定后，ref2 引用 num
    int &ref2 = const_cast<int &>(ref);
    ref2 = 3; // 通过 ref2 修改 num
    std::cout << "num: " << num << ", ref: " << ref
              << std::endl; // 输出：num: 3, ref: 3

    return 0;
}