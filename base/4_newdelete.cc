#include <cstdlib>
#include <iostream>

int main() {
    // c style memory management
    int *c_p = (int *)malloc(sizeof(int)); // type cast => void* to int*
    *c_p = 10;
    printf("%d\n", *c_p);
    free(c_p); // free the memory allocated by malloc
    c_p = NULL;

    // c++ style memory management
    int *p = new int();           // initialize it to 0
    std::cout << *p << std::endl; // default initialize to 0
    *p = 1;
    std::cout << *p << std::endl; // value is 1
    delete p;                     // free the memory allocated by new
    std::cout << *p << std::endl; // undefined behavior, p is a dangling pointer
    p = nullptr;                  // set p to nullptr to avoid dangling pointer

    // val init with parentheses
    int *p1 = new int(10); // initialize to 10
    std::cout << *p1 << std::endl;
    delete p1;

    // value init with empty braces
    int *p2 = new int{}; // value initialize to 0
    std::cout << *p2 << std::endl;
    delete p2;

    // value intit with braces and value
    int *p3 = new int{20}; // value initialize to 20
    std::cout << *p3 << std::endl;
    delete p3;

    int *arr_ptr = new int[3]();               // allocate array of 3 integers
    std::cout << sizeof(arr_ptr) << std::endl; // size of pointer, not the array
    for (int i = 0; i < 3; ++i) {
        std::cout << arr_ptr[i] << std::endl;
    }
    delete[] arr_ptr; // free the array

    int *arr_ptr2 = new int[3]{1, 2, 3}; // initialize array of 3 integers
    for (int i = 0; i < 3; ++i) {
        std::cout << arr_ptr2[i] << std::endl;
    }
    delete[] arr_ptr2; // free the array

    return 0;
}