#include "1_class.hh"

#include <iostream>

/**
 * class 的最常见用途是：
 * 1. 用成员变量保存状态。
 * 2. 用成员函数描述行为。
 *
 * 访问权限最常见的三个关键字：
 * public：类外也能访问。
 * private：只能在类内部访问。
 * protected：类内部和子类中可以访问。
 */

class MyClass {
private:
    int myVariable; // 成员变量，用来保存对象自己的数据。

public:
    void setMyVariable(int value) { myVariable = value; }
    int getMyVariable() { return myVariable; }

    void func(); // 先声明，后面在类外定义。

    void myFunction() {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

void MyClass::func() {
    std::cout << "This is the func() method of MyClass." << std::endl;
}

void MyHeadClass::myHeadFunction() {
    std::cout << "This is the myHeadFunction() method of MyHeadClass."
              << std::endl;
}

/**
 * struct 和 class 很像，也能写成员变量和成员函数。
 * 最直观的区别是：
 * struct 默认成员权限是 public，
 * class 默认成员权限是 private。
 */
struct Student {
    std::string name;
    int age;

    void study() {
        std::cout << name << " is studying." << std::endl;
    }
};

int main() {
    MyClass myObject;
    myObject.setMyVariable(42);
    std::cout << "The value of myVariable is: " << myObject.getMyVariable()
              << std::endl;
    myObject.func();

    MyHeadClass myHeadObject;
    myHeadObject.myHeadFunction();

    Student student;
    student.name = "Alice";
    student.age = 20;
    std::cout << "Student Name: " << student.name << std::endl;
    std::cout << "Student Age: " << student.age << std::endl;
    student.study();
    return 0;
}
