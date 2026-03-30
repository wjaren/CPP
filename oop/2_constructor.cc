#include <iostream>

/**
 * C++ 构造函数（Constructor）是一种特殊的成员函数，用于在创建对象时初始化对象的状态。
 * 构造函数的名称必须与类名相同，并且没有返回类型。
 * 构造函数可以被重载，这意味着一个类可以有多个构造函数，每个构造函数可以接受不同数量或类型的参数。
 * 构造函数的主要作用是为对象分配内存并初始化成员变量。
 * 它们在对象创建时自动调用，无需显式调用。
 * 构造函数的类型：
 * 1. 默认构造函数（Default Constructor）：没有参数的构造函数。
 * 2. 参数化构造函数（Parameterized Constructor）：接受一个或多个参数的构造函数。
 * 3. 复制构造函数（Copy Constructor）：接受一个对象的引用作为参数的构造函数，用于创建一个对象作为另一个对象的副本。
 * 4. 移动构造函数（Move Constructor）：接受一个右值引用作为参数的构造函数，用于将资源从一个对象移动到另一个对象。
 *
 * 没有提供任何构造函数时，编译器会自动生成一个默认构造函数。
 * 如果提供了任何构造函数，编译器将不会自动生成默认构造函数，除非显式定义它。
 */

class MyClass {
private:
    int _x;
    int _y;

public:
    int _value = 10;

public:
    // MyClass() = default; // 显式使用默认构造函数
    MyClass() {
        // 默认构造函数
        std::cout << "Default constructor called" << std::endl;
    }
    // MyClass(int value = 0) {
    //     // 参数化构造函数，带有默认参数, 二义性
    //     std::cout << "Parameterized constructor called with value: " << value << std::endl;
    // }

    MyClass(int value) {
        // 参数化构造函数
        std::cout << "Parameterized constructor called with value: " << value << std::endl;
    }
    MyClass(int x, int y) : _x(x), _y(y) {
        // 参数化构造函数，使用成员初始化列表
        std::cout << "Parameterized constructor called with x: " << x << " and y: " << y << std::endl;
    }

    MyClass(const MyClass &other) {
        // 复制构造函数
        std::cout << "Copy constructor called" << std::endl;
    }

    MyClass(MyClass &&other) {
        // 移动构造函数
        std::cout << "Move constructor called" << std::endl;
    }
};

// 内存对齐
// 内存对齐是指编译器为了提高访问效率而对数据进行的调整，使得数据在内存中的地址满足特定的对齐要求。
// 例如，在大多数系统中，int 类型通常需要 4 字节对齐，double 类型通常需要 8 字节对齐。
// 这意味着编译器会在内存中为这些类型分配足够的空间，并且可能会在结构体中插入填充字节以满足对齐要求。
// 内存对齐可以提高访问速度，但也可能导致内存浪费。
// C++ 用最大对齐原则来确定结构体的对齐方式，即结构体的对齐方式由其成员中最大对齐要求的成员决定。
struct A {
    int a;
    int b;
    double c;
};
struct B {
    int a;
    double b;
    int c;
};
// 空对象的大小为 1 字节，以确保每个对象都有一个唯一的地址。

int main() {
    // MyClass obj0();  // 这不是一个对象，而是一个函数声明，编译器会将其解析为一个函数声明而不是对象实例化。
    MyClass obj1;    // 调用默认构造函数
    MyClass obj1_{}; // 也调用默认构造函数

    MyClass obj2(10);    // 调用参数化构造函数
    MyClass obj2_{1, 2}; // 调用参数化构造函数

    MyClass obj3(obj2); // 调用复制构造函数

    MyClass obj4(std::move(obj2)); // 调用移动构造函数

    MyClass obj(1, 2);                                     // 使用列表初始化，调用参数化构造函数
    std::cout << "默认值: " << obj._value << std::endl;    // 输出默认值
    std::cout << "对象大小: " << sizeof(obj) << std::endl; // 输出对象大小

    A a;
    B b;
    std::cout << "Size of struct A: " << sizeof(a) << std::endl; // 输出 struct A 的大小，内存对齐后为 16 字节
    std::cout << "Size of struct B: " << sizeof(b) << std::endl; // 输出 struct B 的大小，内存对齐后为 24 字节

    return 0;
}