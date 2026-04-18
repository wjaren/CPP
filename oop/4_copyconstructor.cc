#include <cstring>
#include <iostream>

/**
 * 拷贝构造函数在“用一个已有对象初始化另一个对象”时触发。
 * 典型场景：
 * 1. 值传参
 * 2. 函数返回对象
 * 3. 直接用旧对象初始化新对象
 *
 * 如果类里管理了动态资源，就要特别注意“浅拷贝”和“深拷贝”。
 */

class MyClass {
    int num;

public:
    MyClass(int n) : num(n) {
        std::cout << "Default constructor called. Number is " << num
                  << std::endl;
    }

    /**
     * 参数必须写成 const MyClass&：
     * 1. 加 const，表示不会改源对象。
     * 2. 加引用，避免再次拷贝。
     * 如果这里按值传参，会无限递归调用拷贝构造。
     */
    MyClass(const MyClass &rhs) : num(rhs.num) {
        std::cout << "Copy constructor called. Number is " << num << std::endl;
    }

    ~MyClass() {
        // 这里没有动态资源，所以析构函数不用做事。
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
    // this 指针表示“当前这个对象自己”。
    DeepCopyClass(const char *name) : name(nullptr) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        std::cout << "Constructor called. Name is " << this->name << std::endl;
    }

    DeepCopyClass(const DeepCopyClass &rhs) : name(nullptr) {
        // 深拷贝：为新对象重新申请一份内存，而不是共用同一块内存。
        this->name = new char[strlen(rhs.name) + 1];
        strcpy(this->name, rhs.name);

        std::cout << "Copy constructor called. Name is " << this->name
                  << std::endl;
    }

    /**
     * 赋值运算符和拷贝构造函数不是一回事：
     * 1. 拷贝构造：创建新对象时触发
     * 2. operator=：两个已存在对象之间赋值时触发
     */
    DeepCopyClass &operator=(const DeepCopyClass &rhs) {
        if (this == &rhs) { // 先处理自赋值。
            return *this;
        }

        delete[] this->name;

        this->name = new char[strlen(rhs.name) + 1];
        strcpy(this->name, rhs.name);

        std::cout << "Assignment operator called. Name is " << this->name
                  << std::endl;

        return *this;
    }

    ~DeepCopyClass() {
        delete[] this->name;
        this->name = nullptr;
    }
};

int main() {
    MyClass obj1(1);

    MyClass obj2 = obj1;

    int a = 1;
    &a;     // 左值可以取地址。
    &obj1;  // 对象变量也是左值。
    &"abc"; // 字符串字面量也有存储位置。

    // &(a + 1);    // 右值不能取地址。
    // &MyClass(5); // 临时对象是右值。
    // &100;        // 字面量也是右值。

    MyClass obj3 = MyClass(3);

    std::cout << "Enter test function." << std::endl;
    test(obj1);     // 值传参，会触发拷贝构造。
    test_ref(obj1); // 引用传参，不会触发拷贝构造。

    std::cout << "Enter func function." << std::endl;
    MyClass obj4 = func(); // 现代编译器可能会做拷贝省略。

    DeepCopyClass dcc1("obj1");
    DeepCopyClass dcc2("obj2");
    DeepCopyClass dcc3 = dcc1;

    dcc3 = dcc2;

    return 0;
}
