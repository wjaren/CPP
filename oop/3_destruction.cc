#include <cstring>
#include <iostream>

/**
 * 析构函数
 * 析构函数是一个特殊的成员函数，用于在对象生命周期结束时执行清理操作。
 * 它的名称与类名相同，但前面有一个波浪号（~）。
 * 析构函数没有返回类型，也没有参数。
 * 当一个对象被销毁时，析构函数会自动调用。它通常用于释放资源、关闭文件、断开网络连接等清理操作。
 * 如果一个类没有显式定义析构函数，编译器会生成一个默认的析构函数，该函数会自动调用成员对象的析构函数来清理资源。
 */

class MyClass {
    char *type;
    int value;

public:
    MyClass() {
        std::cout << "Constructor called" << std::endl;
    }

    MyClass(const char *type, int value) : value(value), type(new char[strlen(type) + 1]) {
        // 动态分配内存并复制字符串
        strcpy(this->type, type);
        std::cout << "Parameterized constructor called" << std::endl;
        std::cout << "Type: " << this->type << ", Value: " << this->value << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
        std::cout << "Cleaning up resources for type: " << type << std::endl;
        // 释放动态分配的内存
        delete[] type;
        type = nullptr; // 将指针置空，避免悬空指针
    }
};

MyClass globalObj("Global", 200); // 全局对象，程序结束时调用析构函数

int main() {
    std::cout << "Entering main function" << std::endl;

    MyClass localObj("Local", 100); // 创建对象时调用构造函数

    static MyClass staticObj("Static", 150); // 静态对象，程序结束时调用析构函数

    MyClass *dynamicObj = new MyClass("Dynamic", 300); // 动态分配对象
    // 注意：如果不删除动态分配的对象，将会导致内存泄漏
    delete dynamicObj;    // 手动删除对象，调用析构函数
    dynamicObj = nullptr; // 将指针置空，避免悬空指针

    std::cout << "Exiting main function" << std::endl;

    return 0;
}