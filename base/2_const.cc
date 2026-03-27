#include <iostream>

int main() {
    const int num1 = 1;
    // num1 = 10;
    std::cout << "The value of num1 is: " << num1 << std::endl;
    int const num2 = 2;
    // num2 = 20;
    std::cout << "The value of num2 is: " << num2 << std::endl;

    // --> 指向常量的指针
    const int *p1;
    p1 = &num1;
    // *p1 = 10; // 错误：不能给只读位置 '*p1' 赋值
    int const *p2;
    p2 = &num2;
    // *p2 = 20; // 错误：不能给只读位置 '*p2' 赋值
    p1 = p2; // 允许：可以修改 p1 指向的位置，但不能改其指向的值
             // （即不能通过 p1 修改对象值）
    p2 = p1; // 允许：可以修改 p2 指向的位置，但不能改其指向的值
             // （即不能通过 p2 修改对象值）

    // --> 常量指针
    int num3 = 3;
    int *const p3 = &num3;

    // p3 = &num1; // 错误：不能给只读变量 'p3' 赋值
    *p3 = 30; // 允许：可以通过 p3 修改 num3 的值

    const int num4 = 4;
    const int *const p4 = &num4;
    // p4 = &num1; // 错误：不能给只读变量 'p4' 赋值
    // *p4 = 40; // 错误：不能给只读位置 '*p4' 赋值

    return 0;
}