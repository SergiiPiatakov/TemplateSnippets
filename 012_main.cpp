// Class template specialization by derived class.
// Compile and run:
// $ g++ -Wall -Wextra 012_main.cpp -std=c++11 -Wno-unused-variable -o 012_main
// $ ./012_main

#include <iostream>
#include <vector>



struct Animal
{
    virtual void Say () = 0;
};

struct Dog : Animal
{
    void Say () override {std::cout << "Woof." << std::endl;}
};

struct Cat : Animal
{
    void Say () override {std::cout << "MAOOO!!!" << std::endl;}
};



template <typename T>
struct Wrapper
{
    Wrapper (T *) {}
};



int main (int, char **)
{
    // The code below works well.
    Animal * dog = new Dog ();
    Animal * cat = new Cat ();

    std::vector <Animal *> usualAnimals;
    usualAnimals.push_back (dog);
    usualAnimals.push_back (cat);

    for (auto animal : usualAnimals) {
        animal->Say ();
    }


    // The code below does not work well.    
    std::vector <Wrapper <Animal> *> wrappedAnimals;
    // Error: invalid conversion from ‘Animal*’ to ‘Dog*’.
    //Wrapper <Dog> * wdog = new Wrapper <Dog> (dog);
    Wrapper <Dog> * wdog = new Wrapper <Dog> (static_cast <Dog *> (dog) );
    // Error: no matching function for call to ‘std::vector<Wrapper<Animal>*>::push_back(Wrapper<Dog>*&)’.
    //wrappedAnimals.push_back (wdog);
   
    return EXIT_SUCCESS;
}
