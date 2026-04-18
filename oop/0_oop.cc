#include <iostream>

/**
 * OOP（面向对象编程）可以先把它理解成：
 * “把数据和操作数据的函数放到一起，再通过对象来组织程序。”
 *
 * 对初学者最重要的三个关键词：
 * 1. 封装：把数据包在类里，通过接口访问。
 * 2. 继承：让新类复用旧类的能力。
 * 3. 多态：同一个接口，不同对象表现不同。
 */

class Animal {
private:
    std::string name;

public:
    void behavior() { std::cout << "Animal is behaving." << std::endl; }

    // virtual 让子类可以重写这个函数，体现多态。
    virtual void eat() { std::cout << "Animal is eating." << std::endl; }

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
    Animal animal;
    animal.behavior();

    Dog dog;
    dog.behavior(); // Dog 没有自己写 behavior，所以直接继承自 Animal。

    Cat cat;
    cat.setName("Whiskers");
    std::cout << "The cat's name is: " << cat.getName() << std::endl;

    animal.eat();
    dog.eat();
    cat.eat();

    return 0;
}
