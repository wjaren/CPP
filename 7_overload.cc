#include <iostream>

/**
 * overload is a feature in C++ that allows you to define multiple functions
 * with the same name but different parameter types or numbers of parameters.
 * The compiler determines which function to call based on the arguments passed
 * to the function.
 */

int add(int a, int b) { return a + b; }

double add(double a, double b) { return a + b; }

/**
 * c++23 introduces a new feature called "auto function parameters" that allows
 * you to use auto as a parameter type in a function declaration. This allows
 * the compiler to deduce the type of the parameter based on the arguments
 * passed to the function. This can be useful for writing generic functions that
 * can work with different types of data without having to write multiple
 * overloads for each type.
 */

auto add(auto a, auto b) { return a + b; }

void print() { std::cout << "print() called" << std::endl; }

void print(int x) { std::cout << "print(int) called with " << x << std::endl; }

void print(double x) {
    std::cout << "print(double) called with " << x << std::endl;
}

void default_print(int a = 0, int b = 0) {
    std::cout << "default_print(int, int) called with " << a << " and " << b
              << std::endl;
}

/**
 * This will cause a compilation error because default parameters must be
 * specified in the function declaration, not in the function definition. In
 * this case, the compiler will not know how to call the function when only one
 * argument is provided, because it will not know what value to use for the
 * second parameter.
 */
// void default_print(int a = 0, int b) {
//     std::cout << "default_print(int, int) called with " << a << " and " << b
//               << std::endl;
// }

extern "C" {
// This function can be called from C code
int add_c(int a, int b) { return a + b; }
// int add_c(double a, double b) { return a + b; }
// This function can be called from C code, but it will cause a linker error
}

int main() {
    std::cout << "1 + 2 = " << add(1, 2)
              << std::endl; // calls add(int, int), return type is int
    std::cout << "1.5 + 2.5 = " << add(1.5, 2.5)
              << std::endl; // calls add(double, double), return type is double

    print();     // calls print(), no parameters
    print(42);   // calls print(int), parameter is int
    print(3.14); // calls print(double), parameter is double

    default_print();  // calls default_print(int, int) with default parameters
    default_print(5); // calls default_print(int, int) with a = 5
    default_print(5, 10); // calls default_print(int, int) with a = 5 and b = 10

    return 0;
}