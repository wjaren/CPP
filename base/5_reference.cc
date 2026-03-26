#include <iostream>

// not copying values, but modifying the original variables through references
void test_swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int x = 10;
    int &lref = x;                              // lvalue reference to x
    std::cout << "lref: " << lref << std::endl; // output: 10
    lref = 20;                                  // modify x through lref
    std::cout << "x: " << x << std::endl;       // output: 20
    lref = x;                                   // assign x to itself through lref, no change
    std::cout << "x: " << x << std::endl;       // output: 20

    int *p = &x; // pointer to x
    std::cout << "&p: " << &p << ", p: " << p << ", *p: " << *p
              << std::endl; // output: address of x, value of x (20)
    std::cout << "&lref: " << &lref
              << std::endl; // output: address of x (same as p)

    int a = 1, b = 2;
    std::cout << "Before swap: a = " << a << ", b = " << b
              << std::endl; // output: a = 1, b = 2
    test_swap(a, b);        // swap a and b using references
    std::cout << "After swap: a = " << a << ", b = " << b
              << std::endl; // output: a = 2, b = 1

    const int &ref = x;                       // const reference to x
    std::cout << "ref: " << ref << std::endl; // output: 20
    // ref = 30; // error: cannot modify a const reference

    // int &&rref = 30; // rvalue reference to a temporary
    // std::cout << "rref: " << rref << std::endl; // output: 30
    // rref = 40; // modify the temporary through rref
    // std::cout << "rref: " << rref << std::endl; // output: 40

    return 0;
}