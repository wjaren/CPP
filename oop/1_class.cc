#include "1_class.hh"

#include <iostream>

/**
 * class ClassName {
 *   // 类成员（变量和函数）
 * };
 */

/**
 * 类命名规则：
 * - 大驼峰（PascalCase）：类名（ClassName）
 * - 小驼峰（camelCase）：类成员（变量和函数）
 */

/**
 * public：可在类外访问的成员
 * private：只能在类内访问的成员
 * protected：可在类内和派生类中访问的成员
 */

class MyClass {
private:
    int myVariable; // 类成员变量

public:
    void setMyVariable(int value) { // 类成员函数
        myVariable = value;
    }
    int getMyVariable() { // 类成员函数
        return myVariable;
    }

public:
    void func(); // 类成员函数声明

    void myFunction() { // 类成员函数
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

void MyClass::func() { // 类成员函数定义
    std::cout << "This is the func() method of MyClass." << std::endl;
}

void MyHeadClass::myHeadFunction() { // 类成员函数定义
    std::cout << "This is the myHeadFunction() method of MyHeadClass." << std::endl;
}

int main() {

    MyClass myObject;           // 创建 MyClass 实例
    myObject.setMyVariable(42); // 通过 setMyVariable 设置 myVariable 的值
    std::cout << "The value of myVariable is: "
              << myObject.getMyVariable()
              << std::endl; // 通过 getMyVariable 获取 myVariable 的值
    myObject.func();        // 调用 MyClass 的 func 方法

    MyHeadClass myHeadObject;      // 创建 MyHeadClass 实例
    myHeadObject.myHeadFunction(); // 调用 MyHeadClass 的 myHeadFunction 方法

    return 0;
}