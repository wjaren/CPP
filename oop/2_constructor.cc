#include <iostream>
#include <utility>

/**
 * 构造函数会在“对象创建时”自动调用。
 * 它最主要的作用是让对象一出生就处于合法状态。
 *
 * 常见种类：
 * 1. 默认构造：没有参数。
 * 2. 有参构造：带参数。
 * 3. 拷贝构造：用同类对象初始化新对象。
 * 4. 移动构造：把临时对象的资源“搬过来”。
 */

class MyClass {
private:
    int _x;
    int _y;

public:
    int _value = 10;

public:
    MyClass() {
        std::cout << "Default constructor called" << std::endl;
    }

    MyClass(int value) {
        std::cout << "Parameterized constructor called with value: " << value
                  << std::endl;
    }

    // 成员初始化列表通常比“先默认构造再赋值”更自然。
    MyClass(int x, int y) : _x(x), _y(y) {
        std::cout << "Parameterized constructor called with x: " << x
                  << " and y: " << y << std::endl;
    }

    MyClass(const MyClass &other) {
        std::cout << "Copy constructor called" << std::endl;
    }

    MyClass(MyClass &&other) {
        std::cout << "Move constructor called" << std::endl;
    }
};

// 内存对齐可以先简单理解成：
// “编译器为了访问效率，会按某些边界摆放数据”。
// 所以成员顺序不同，结构体大小也可能不同。
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

// 即使是空对象，也至少要占 1 个字节，
// 这样每个对象才有自己独立的地址。

int main() {
    // MyClass obj0(); // 这不是创建对象，而是函数声明，叫“最烦人的解析”。
    MyClass obj1;
    MyClass obj1_{};

    MyClass obj2(10);
    MyClass obj2_{1, 2};

    MyClass obj3(obj2);

    MyClass obj4(std::move(obj2));

    MyClass obj(1, 2);
    std::cout << "默认值: " << obj._value << std::endl;
    std::cout << "对象大小: " << sizeof(obj) << std::endl;

    A a;
    B b;
    std::cout << "Size of struct A: " << sizeof(a) << std::endl;
    std::cout << "Size of struct B: " << sizeof(b) << std::endl;

    return 0;
}
