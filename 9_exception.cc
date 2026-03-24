#include <iostream>

int divide(int a, int b) {
    if (b == 0) {
        throw 0;
        throw "Division by zero is not allowed";
        throw std::runtime_error("Division by zero is not allowed");
    }
    return a / b;
}

int main() {

    try {
        divide(10, 0);
        // Simulate an error
        throw std::runtime_error("An error occurred");
    } catch (const int e) {
        std::cerr << "Caught exception: " << e << std::endl;
    } catch (const char *e) {
        // Handle the exception
        std::cerr << "Caught exception: " << e << std::endl;
    } catch (const std::exception &e) {
        // Handle the exception
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}