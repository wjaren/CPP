#include <iostream>

/**
 * OOP（面向对象编程）是一种使用“对象”来设计程序的编程范式。
 * 它吸收了早期范式中的多种思想，包括模块化、多态和封装。
 * OOP 的核心目标是把数据与操作这些数据的函数绑定在一起，从而限制外部代码对数据的直接访问。
 *
 * 模块化（modularity）：
 * 一个对象的源码可以独立于其他对象进行编写和维护。
 *
 * 多态（polymorphism）：
 * 不同对象可以用各自的方式响应相同的消息（或方法调用）。
 *
 * 封装（encapsulation）：
 * 将数据与操作数据的方法打包在一起，或限制对对象部分成员的直接访问。
 */

class Animal {
private:
    std::string name;

public:
    void behavior() { std::cout << "Animal is behaving." << std::endl; }
    virtual void eat() { std::cout << "Animal is eating." << std::endl; }

public:
    void setName(std::string name) { this->name = name; }
    std::string getName() { return name; }
};

class Dog : public Animal {
public:
    void eat() { std::cout << "Dog is eating dog food." << std::endl; }
};

class Cat : public Animal {
public:
    void eat() { std::cout << "Cat is eating cat food." << std::endl; }
};

int main() {
    Animal animal;     // 创建 Animal 类实例
    animal.behavior(); // 调用 Animal 类的 behavior 方法

    Dog dog;        // 创建 Dog 类实例
    dog.behavior(); // 调用 Dog 的 behavior 方法（继承自 Animal）

    Cat cat;                 // 创建 Cat 类实例
    cat.setName("Whiskers"); // 使用 setName 方法设置猫的名字
    std::cout << "The cat's name is: "
              << cat.getName() << std::endl; // 使用 getName 方法获取猫的名字

    animal.eat(); // 调用 Animal 类的 eat 方法
    dog.eat();    // 调用 Dog 类的 eat 方法（重写自 Animal）
    cat.eat();    // 调用 Cat 类的 eat 方法（重写自 Animal）

    return 0;
}