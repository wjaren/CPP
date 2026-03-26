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
    // This is an unnamed namespace, which gives internal linkage to its members.
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

    displayMessage(); // Calls the function from the unnamed namespace
    std::cout << "Name in the unnamed namespace: " << name << std::endl;

    return 0;
}