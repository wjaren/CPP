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

    // 命名空间还可以继续嵌套，用来把名字分得更细。
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
    // 匿名命名空间里的名字只在当前源文件可见，
    // 常用来放“不想暴露到其他文件”的变量或函数。
    std::string name = "UnnamedNamespace";
    void displayMessage() {
        std::cout << "Hello from the unnamed namespace!" << std::endl;
    }
} // namespace

int main() {
    MyNamespace::displayMessage();
    std::cout << "Name in MyNamespace: " << MyNamespace::name << std::endl;

    AnotherNamespace::displayMessage();
    std::cout << "Name in AnotherNamespace: " << AnotherNamespace::name
              << std::endl;

    OuterNamespace::InnerNamespace::displayMessage();
    std::cout << "Name in InnerNamespace: "
              << OuterNamespace::InnerNamespace::name << std::endl;

    OuterNamespace::displayMessage();
    std::cout << "Name in OuterNamespace: " << OuterNamespace::name
              << std::endl;

    // 匿名命名空间中的名字可以像当前文件内的普通函数一样直接使用。
    displayMessage();
    std::cout << "Name in the unnamed namespace: " << name << std::endl;

    return 0;
}
