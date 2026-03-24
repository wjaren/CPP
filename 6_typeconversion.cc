#include <iostream>

int main() {

    // c style cast
    double c_d = 3.14;
    int c_i = (int)c_d; // implicit conversion from double to int, c_i becomes 3
    std::cout << "c_d: " << c_d << ", c_i: " << c_i
              << std::endl; // output: c_d: 3.14, c_i: 3
    int *c_p = (int *)&c_d; // reinterpret cast, treating the bits of c_d as an
                            // int pointer
    std::cout << "c_p: " << c_p << ", *c_p: " << *c_p
              << std::endl; // output: c_p: address of c_d, *c_p: some integer
                            // value (undefined behavior)

    // C++ style casts
    // static cast
    double cpp_d = 3.14;
    int cpp_i = static_cast<int>(cpp_d); // static cast, converts double to int
    std::cout << "cpp_d: " << cpp_d << ", cpp_i: " << cpp_i
              << std::endl; // output: cpp_d: 3.14, cpp_i: 3

    // static cast, treating the address of cpp_d as an int pointer
    // int *cpp_p = static_cast<int *>(&cpp_d);
    // error: cannot static_cast from double* to int*

    // const cast
    int num = 1;
    const int *p = &num; // pointer to const int
    // *p = 2; // error: cannot modify a const int through p
    int *q = const_cast<int *>(p); // remove const qualifier, q points to num
    *q = 2;                        // modify num through q
    std::cout << "num: " << num << ", *p: " << *p
              << std::endl; // output: num: 2, *p: 2
    const int &ref = num;   // reference to const int
    // ref = 3; // error: cannot modify a const int through ref
    // remove const qualifier, ref2 refers to num
    int &ref2 = const_cast<int &>(ref);
    ref2 = 3; // modify num through ref2
    std::cout << "num: " << num << ", ref: " << ref
              << std::endl; // output: num: 3, ref: 3

    return 0;
}