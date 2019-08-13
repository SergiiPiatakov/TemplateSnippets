// Class template inheritance.
// Compile and run:
// $ g++ -Wall -Wextra 014_main.cpp -std=c++11 -o 014_main
// $ ./014_main

#include <iostream>
#include <vector>


struct Animal
{
    virtual void Say () = 0;
};

template <typename T>
struct Dog : Animal
{
    void Say () override {std::cout << "Woof." << std::endl;}
};

template <typename T>
struct Cat : Animal
{
    void Say () override {std::cout << "MEAUUU!!!" << std::endl;}
};



int main (int, char **)
{
    Animal * dog = new Dog<int> ();
    Animal * cat = new Cat<float> ();

    std::vector <Animal *> bindedAnimals;
    bindedAnimals.push_back (dog);
    bindedAnimals.push_back (cat);

    for (auto animal : bindedAnimals) {
        animal->Say ();
    }

    return EXIT_SUCCESS;
}
