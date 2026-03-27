#include <iostream>
#include <string>

namespace MyNamespace {
    std::string name = "MyNamespace";
    void displayMessage() { std::cout << "Hello from MyNamespace!" << std::endl; }
} // namespace MyNamespace

namespace AnotherNamespace {
    std::string name = "AnotherNamespace";
    void displayMessage() {
        std::cout << "Hello from AnotherNamespace!" << std::endl;
    }
} // namespace AnotherNamespace

namespace OuterNamespace {
    std::string name = "OuterNamespace";
    namespace InnerNamespace {
        std::string name = "InnerNamespace";
        void displayMessage() {
            std::cout << "Hello from InnerNamespace!" << std::endl;
        }
    } // namespace InnerNamespace
    void displayMessage() {
        std::cout << "Hello from OuterNamespace!" << std::endl;
    }
} // namespace OuterNamespace

namespace {
    // 这是一个未命名命名空间，其成员具有内部链接属性。
    std::string name = "UnnamedNamespace";
    void displayMessage() {
        std::cout << "Hello from the unnamed namespace!" << std::endl;
    }

} // namespace

// std::string name = "GlobalNamespace";
// void displayMessage() {
//     std::cout << "Hello from the global namespace!" << std::endl;
// }

int main() {
    MyNamespace::displayMessage();                                          // 调用 MyNamespace 中的函数
    std::cout << "Name in MyNamespace: " << MyNamespace::name << std::endl; // 访问 MyNamespace 中的变量

    AnotherNamespace::displayMessage(); // 调用 AnotherNamespace 中的函数
    std::cout << "Name in AnotherNamespace: " << AnotherNamespace::name
              << std::endl; // 访问 AnotherNamespace 中的变量

    OuterNamespace::InnerNamespace::displayMessage(); // 调用 OuterNamespace::InnerNamespace 中的函数
    std::cout << "Name in InnerNamespace: "
              << OuterNamespace::InnerNamespace::name << std::endl; // 访问 OuterNamespace::InnerNamespace 中的变量

    OuterNamespace::displayMessage(); // 调用 OuterNamespace 中的函数
    std::cout << "Name in OuterNamespace: " << OuterNamespace::name
              << std::endl; //

    displayMessage(); // 调用未命名命名空间中的函数
    std::cout << "Name in the unnamed namespace: " << name << std::endl;

    return 0;
}