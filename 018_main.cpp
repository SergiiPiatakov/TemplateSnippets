// Mixins.
// Compile and run:
// $ g++ -Wall -Wextra 018_main.cpp -o 018_main
// $ ./018_main

#include <string>
#include <iostream>
#include <cstdlib>

struct Dog
{
    std::string Voice () const {return "Woof.";}
};

template <typename T>
struct Gentler : T
{
    std::string Voice () const {return "Hello! " + T::Voice ();}
};

template <typename T>
struct Teenager : T
{
    std::string Voice () const {return T::Voice () + " Yeah!";}
};

// Helper.
template <typename T>
void Say (const T & x)
{
    std::cout << x.Voice () << std::endl;
}

int main (int, char **)
{
    Dog dog;
    Gentler <Dog> gentlyDog;
    Teenager <Dog> teenagerDog;
    Gentler <Teenager <Dog> > gentlyTeenagerDog;

    Say (dog);
    Say (gentlyDog);
    Say (teenagerDog);
    Say (gentlyTeenagerDog);

    return EXIT_SUCCESS;
}
