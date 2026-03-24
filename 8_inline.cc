#include <iostream>

#define MAX(a, b) (a) > (b) ? (a) : (b)
// #define MAX(a, b) ((a) > (b) ? (a) : (b))
// This is a safer version of the macro

/**
 * inline functions are a powerful feature in C++ that allows the compiler to
 * replace a function call with the actual code of the function. This can lead
 * to faster execution since it eliminates the overhead of a function call.
 * However, it's important to use inline functions judiciously, as excessive
 * inlining can lead to code bloat and may not always result in performance
 * gains.
 */
inline int max(int a, int b) { return a > b ? a : b; }

int main() {
    int a = MAX(10, 5) + 1; // This will expand to (10) > (5) ? (10) : (5) + 1
    std::cout << "The maximum value is: " << a << std::endl; // 10

    int b = max(10, 5) + 1; // This will call the inline function max
    std::cout << "The maximum value is: " << b << std::endl; // 11
    return 0;
}