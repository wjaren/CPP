#include <iostream>

int main() {
    const int num1 = 1;
    // num1 = 10; // 错误：const 变量一旦初始化，值就不能再改。
    std::cout << "The value of num1 is: " << num1 << std::endl;

    int const num2 = 2;
    // num2 = 20; // 和上面是同一种写法，只是 const 位置不同。
    std::cout << "The value of num2 is: " << num2 << std::endl;

    // 指向常量的指针：可以改“指向谁”，不能改“指向的值”。
    const int *p1;
    p1 = &num1;
    // *p1 = 10; // 错误：不能通过 p1 修改它指向的内容。

    int const *p2;
    p2 = &num2;
    // *p2 = 20; // 同样不允许。

    p1 = p2; // 允许：p1 本身不是常量，可以重新指向别处。
    p2 = p1;

    // 常量指针：指针本身不能改，但可以改它指向的值。
    int num3 = 3;
    int *const p3 = &num3;
    // p3 = &num1; // 错误：p3 不能改成指向其他地址。
    *p3 = 30; // 允许：num3 不是常量。

    // 既不能改指向，也不能改值。
    const int num4 = 4;
    const int *const p4 = &num4;
    // p4 = &num1; // 错误
    // *p4 = 40;   // 错误

    return 0;
}
