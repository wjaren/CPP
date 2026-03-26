#include <iostream>

int main() {
    const int num1 = 1;
    // num1 = 10;
    std::cout << "The value of num1 is: " << num1 << std::endl;
    int const num2 = 2;
    // num2 = 20;
    std::cout << "The value of num2 is: " << num2 << std::endl;

    // --> pointer to constant
    const int *p1;
    p1 = &num1;
    // *p1 = 10; // error: assignment of read-only location '*p1'
    int const *p2;
    p2 = &num2;
    // *p2 = 20; // error: assignment of read-only location '*p2
    p1 = p2; // allowed: we can change where p1 points to, but not the value it
             // points to
    p2 = p1; // allowed: we can change where p2 points to, but not the value it
             // points to

    // --> constant pointer
    int num3 = 3;
    int *const p3 = &num3;

    // p3 = &num1; // error: assignment of read-only variable 'p3'
    *p3 = 30; // allowed: we can change the value of num3 through p3

    const int num4 = 4;
    const int *const p4 = &num4;
    // p4 = &num1; // error: assignment of read-only variable 'p4'
    // *p4 = 40; // error: assignment of read-only location '*p4'

        return 0;
}