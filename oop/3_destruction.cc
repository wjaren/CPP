#include <cstring>
#include <iostream>

/**
 * 析构函数会在对象生命周期结束时自动调用。
 * 它最常见的用途是“善后”：
 * 1. 释放动态内存
 * 2. 关闭文件
 * 3. 释放锁或网络连接
 */

class MyClass {
    char *type;
    int value;

public:
    MyClass() {
        std::cout << "Constructor called" << std::endl;
    }

    MyClass(const char *type, int value)
        : value(value), type(new char[strlen(type) + 1]) {
        strcpy(this->type, type);
        std::cout << "Parameterized constructor called" << std::endl;
        std::cout << "Type: " << this->type << ", Value: " << this->value
                  << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
        std::cout << "Cleaning up resources for type: " << type << std::endl;
        delete[] type;
        type = nullptr;
    }
};

// 全局对象会在 main 执行前构造，在程序结束时析构。
MyClass globalObj("Global", 200);

int main() {
    std::cout << "Entering main function" << std::endl;

    MyClass localObj("Local", 100); // 局部对象离开作用域时析构。

    static MyClass staticObj("Static", 150); // 程序结束时析构。

    MyClass *dynamicObj = new MyClass("Dynamic", 300);
    // 动态对象不会自动释放，需要手动 delete。
    delete dynamicObj;
    dynamicObj = nullptr;

    std::cout << "Exiting main function" << std::endl;

    return 0;
}
