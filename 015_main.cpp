// Member-function template inheritance.
// Compile and run:
// $ g++ -Wall -Wextra 015_main.cpp -std=c++11 -o 015_main
// $ ./015_main

#include <iostream>
#include <vector>


struct Animal
{
    // Error: templates may not be ‘virtual’.
    //template <typename T>
    virtual void Say () = 0;
};

struct Dog : Animal
{
    // Error: member template ‘void Dog::Say()’ may not have virt-specifiers.
    //template <typename T>
    void Say () override {std::cout << "Woof." << std::endl;}
};

struct Cat : Animal
{
    // Error: member template ‘void Cat::Say()’ may not have virt-specifiers.
    //template <typename T>
    void Say () override {std::cout << "MEAUUU!!!" << std::endl;}
};



int main (int, char **)
{
    Animal * dog = new Dog ();
    Animal * cat = new Cat ();

    std::vector <Animal *> featuredAnimals;
    featuredAnimals.push_back (dog);
    featuredAnimals.push_back (cat);

    for (auto animal : featuredAnimals) {
        //animal->Say<int> ();
        animal->Say ();
    }



    return EXIT_SUCCESS;
}
