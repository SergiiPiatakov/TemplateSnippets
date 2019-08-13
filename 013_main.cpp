// Class template inheritance.
// Compile and run:
// $ g++ -Wall -Wextra 013_main.cpp -std=c++11 -o 013_main
// $ ./013_main

#include <iostream>
#include <vector>


template <typename T>
struct Animal
{
    virtual void Say () = 0;
};

template <typename T>
struct Dog : Animal <T>
{
    void Say () override {std::cout << "Woof." << std::endl;}
};

template <typename T>
struct Cat : Animal <T>
{
    void Say () override {std::cout << "MEAUUU!!!" << std::endl;}
};



int main (int, char **)
{
    Animal<int> * dog = new Dog<int> ();
    Animal<int> * cat = new Cat<int> ();

    std::vector <Animal<int> *> intedAnimals;
    intedAnimals.push_back (dog);
    intedAnimals.push_back (cat);

    for (auto animal : intedAnimals) {
        animal->Say ();
    }

    return EXIT_SUCCESS;
}
