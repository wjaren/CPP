#include <cstring>
#include <iostream>

/**
 * 拷贝构造函数（Copy Constructor）是C++中的一种特殊构造函数，用于创建一个对象作为另一个同类型对象的副本。
 * 它的主要作用是在对象被复制时执行特定的操作，例如深复制（deep copy）或资源管理。
 * 拷贝构造函数的定义通常如下：
 *      ClassName(const ClassName& rhs);
 * 其中，`ClassName`是类的名称，`rhs`是要复制的对象的引用。
 *
 * 调用时机
 * - 当一个对象以值传递的方式传递给函数时，会调用拷贝构造函数来创建一个副本。
 * - 当一个对象以值返回的方式从函数返回时，会调用拷贝构造函数来创建一个副本。
 * - 当一个对象被用来初始化另一个对象时，会调用拷贝构造函数来创建一个副本。
 *
 * 浅拷贝（Shallow Copy）和深拷贝（Deep Copy）是两种不同的对象复制方式：
 * - 浅拷贝：仅复制对象的成员变量的值，如果成员变量是指针，则复制指针的地址，导致多个对象共享同一块内存。
 * - 深拷贝：不仅复制对象的成员变量的值，还为指针成员分配新的内存，并复制指针指向的数据，确保每个对象都有自己的独立资源。
 */

/**
 * 左值（Lvalue）和右值（Rvalue）是C++中的两个重要概念：
 * - 左值：表示一个对象的地址，可以出现在赋值语句的左边。左值通常是一个变量、函数返回的引用或一个对象的成员。
 * - 右值：表示一个临时对象或一个字面值，不能出现于赋值语句的左边。右值通常是一个表达式的结果、一个字面值或一个函数返回的非引用类型。
 * 在C++11及以后的版本中，引入了右值引用（Rvalue Reference）和移动语义（Move Semantics），使得资源管理更加高效。
 * 右值引用使用双引号（&&）表示，可以绑定到右值上，允许资源的移动而不是复制，从而提高性能。
 */

/**
 * c++17 引入了复制省略（Copy Elision）和返回值优化（Return Value Optimization, RVO）等优化技术，可以在某些情况下避免调用拷贝构造函数，从而提高性能。
 * 例如，在返回一个局部对象时，编译器可以直接在调用者的内存中构造对象，而不是先构造一个临时对象再进行复制。
 * 在C++23中，复制省略已经成为了强制性的优化，编译器必须在满足条件的情况下进行复制省略，这意味着在某些情况下，拷贝构造函数可能不会被调用，即使代码中看起来需要调用它。
 */

class MyClass {
    int num;

public:
    MyClass(int n) : num(n) {
        std::cout << "Default constructor called. Number is " << num << std::endl;
    }

    /**
     * const 可以保证如果是右值也可以绑定到这个拷贝构造函数上，右值不能绑定到非常量引用。
     * 并且可以防止在拷贝构造函数中修改被复制对象的成员变量，确保对象的状态不被意外改变。
     *
     * 不加 &，参数将是一个值传递的对象，这会导致无限递归调用拷贝构造函数
     * 因为在传递参数时需要创建一个副本，而这个副本又需要调用拷贝构造函数来创建它自己，最终导致栈溢出。
     *
     * rhs 是 "right-hand side" 的缩写，表示赋值操作中等号右边的对象。在拷贝构造函数中，rhs 是要复制的对象的引用。
     */
    MyClass(const MyClass &rhs) : num(rhs.num) {
        std::cout << "Copy constructor called. Number is " << num << std::endl;
    }

    ~MyClass() {
        // std::cout << "Destructor called." << std::endl;
    }
};

void test(MyClass obj) {
    std::cout << "In test function." << std::endl;
}

void test_ref(const MyClass &obj) {
    std::cout << "In test_ref function." << std::endl;
}

MyClass func() {
    return MyClass(4);
}

class DeepCopyClass {
    char *name;

public:
    // this指针是一个隐式参数，指向当前对象的地址，可以通过它来访问对象的成员变量和成员函数。
    // 在构造函数中，this指针用于区分成员变量和参数名相同的情况，确保正确地初始化成员变量。
    // 无歧义的情况下，this指针也可以省略，但在有歧义的情况下必须使用它来明确指代成员变量。
    DeepCopyClass(const char *name) : name(nullptr) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        std::cout << "Constructor called. Name is " << this->name << std::endl;
    }

    DeepCopyClass(const DeepCopyClass &rhs) : name(nullptr) {
        // this->name = rhs.name; // 浅拷贝，多个对象共享同一块内存 导致释放时出现问题（重复释放）
        this->name = new char[strlen(rhs.name) + 1]; // 深拷贝，为每个对象分配独立的内存
        strcpy(this->name, rhs.name);                // 复制字符串内容

        std::cout << "Copy constructor called. Name is " << this->name << std::endl;
    }

    /**
     * 默认的赋值运算符（operator=）会执行浅拷贝，导致多个对象共享同一块内存，可能会引发资源管理问题（如重复释放）。
     * 因此，在需要深拷贝的类中，应该显式定义赋值运算符，确保正确地管理资源，避免内存泄漏和重复释放等问题。
     * 返回值类型是 DeepCopyClass&，表示返回当前对象的引用，这样可以支持链式赋值（如 a = b = c）。
     */
    DeepCopyClass &operator=(const DeepCopyClass &rhs) {
        if (this == &rhs) { // 自我赋值检查
            return *this;
        }

        delete[] this->name; // 释放当前对象的资源

        this->name = new char[strlen(rhs.name) + 1]; // 为新资源分配内存
        strcpy(this->name, rhs.name);                // 复制字符串内容

        std::cout << "Assignment operator called. Name is " << this->name << std::endl;

        return *this; // 返回当前对象的引用
    }

    ~DeepCopyClass() {
        delete[] this->name;
        this->name = nullptr;
    }
};

int main() {
    MyClass obj1(1);

    // 如果没有显式定义拷贝构造函数，编译器会自动生成一个默认的拷贝构造函数，执行浅拷贝。
    MyClass obj2 = obj1; // 这里会调用拷贝构造函数
    // Myclass obj2(obj1); // 这里也会调用拷贝构造函数
    // Myclass obj2{obj1}; // 这里也会调用拷贝构造函数

    int a = 1;
    &a;     // a是一个左值，可以取地址
    &obj1;  // obj1是一个左值，可以取地址
    &"abc"; // "abc"是左值可以取地址

    // &(a + 1);    // a + 1是一个右值，不能取地址
    // &MyClass(5); // MyClass(5)是一个右值，不能取地址
    // &100;        // 100是一个右值，不能取地址

    // int &ref = a;           // ref是a的一个引用，ref是一个左值
    // int &ref2 = a + 1;      // 错误，a + 1是一个右值，不能绑定到左值引用
    // const int &ref = a + 1; // 正确，a + 1是一个右值，可以绑定到const int&
    MyClass obj3 = MyClass(3); // 这里会调用拷贝构造函数，MyClass(3)是一个右值，可以绑定到const MyClass&

    std::cout << "Enter test function." << std::endl;
    test(obj1);     // 这里会调用拷贝构造函数
    test_ref(obj1); // 这里不会调用拷贝构造函数

    std::cout << "Enter func function." << std::endl;
    MyClass obj4 = func(); // 这里会调用拷贝构造函数

    DeepCopyClass dcc1("obj1");
    DeepCopyClass dcc2("obj2");
    DeepCopyClass dcc3 = dcc1; // 这里会调用拷贝构造函数

    // 这里不会调用拷贝构造函数，而是调用默认的赋值运算符，导致浅拷贝问题 需要重载赋值运算符来解决
    dcc3 = dcc2;

    return 0;
}