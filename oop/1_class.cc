#include "1_class.hh"

#include <iostream>

/**
 * class ClassName {
 *   // class members (variables and functions)
 * };
 */

/**
 * class name rules:
 * - big camel case (PascalCase): class name (ClassName)
 * - small camel case (camelCase): class members (variables and functions)
 */

/**
 * public: class members that can be accessed from outside the class
 * private: class members that can only be accessed from within the class
 * protected: class members that can be accessed from within the class and by derived classes
 */

class MyClass {
private:
    int myVariable; // class member variable

public:
    void setMyVariable(int value) { // class member function
        myVariable = value;
    }
    int getMyVariable() { // class member function
        return myVariable;
    }

public:
    void func(); // class member function declaration

    void myFunction() { // class member function
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

void MyClass::func() { // class member function definition
    std::cout << "This is the func() method of MyClass." << std::endl;
}

void MyHeadClass::myHeadFunction() { // class member function definition
    std::cout << "This is the myHeadFunction() method of MyHeadClass." << std::endl;
}

int main() {

    MyClass myObject;           // Create an instance of MyClass
    myObject.setMyVariable(42); // Set the value of myVariable using the setMyVariable method
    std::cout << "The value of myVariable is: "
              << myObject.getMyVariable()
              << std::endl; // Get the value of myVariable using the getMyVariable method
    myObject.func();        // Call the func method of MyClass

    MyHeadClass myHeadObject;      // Create an instance of MyHeadClass
    myHeadObject.myHeadFunction(); // Call the myHeadFunction method of MyHeadClass

    return 0;
}