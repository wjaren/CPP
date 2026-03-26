#include <iostream>

/**
 * oop is a programming paradigm that uses "objects" to design applications and computer programs.
 * It utilizes several techniques from previously established paradigms, including modularity,
 * polymorphism, and encapsulation.
 * The main goal of OOP is to bind together the data and the functions that operate on that data,
 * so that no other part of the code can access this data except that function.
 *
 * modularity:
 * the source code for an object can be written and maintained independently of the source
 * code for other objects.
 * 
 * polymorphism:
 * the ability of different objects to respond, each in its own way, to identical
 * messages (or methods).
 * 
 * encapsulation:
 * the bundling of data with the methods that operate on that data, or the restricting
 * of direct access to some of an object's components.
 */

class Animal {
private:
    std::string name;

public:
    void behavior() { std::cout << "Animal is behaving." << std::endl; }
    virtual void eat() { std::cout << "Animal is eating." << std::endl; }

public:
    void setName(std::string name) { this->name = name; }
    std::string getName() { return name; }
};

class Dog : public Animal {
public:
    void eat() { std::cout << "Dog is eating dog food." << std::endl; }
};

class Cat : public Animal {
public:
    void eat() { std::cout << "Cat is eating cat food." << std::endl; }
};

int main() {
    Animal animal;     // Create an instance of the Animal class
    animal.behavior(); // Call the behavior method of the Animal class

    Dog dog;        // Create an instance of the Dog class
    dog.behavior(); // Call the behavior method of the Dog class (inherited from Animal)

    Cat cat;                 // Create an instance of the Cat class
    cat.setName("Whiskers"); // Set the name of the cat using the setName method
    std::cout << "The cat's name is: "
              << cat.getName() << std::endl; // Get the name of the cat using the getName method

    animal.eat(); // Call the eat method of the Animal class
    dog.eat();    // Call the eat method of the Dog class (overridden from Animal)
    cat.eat();    // Call the eat method of the Cat class (overridden from Animal)

    return 0;
}