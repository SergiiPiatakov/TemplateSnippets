// Mixins.
// Compile and run:
// $ g++ -Wall -Wextra 017_main.cpp -o 017_main
// $ ./017_main

#include <string>
#include <iostream>
#include <cstdlib>

template <typename T>
struct Animal : T
{
    void Say () {std::cout << this->Voice () << std::endl;}
};

struct Dog
{
    std::string Voice () {return "Woof.";}
};

struct Cat
{
    std::string Voice () {return "OUUUAAA!";}
};

int main (int, char **)
{
    Animal <Dog> dog;
    Animal <Cat> cat;

    dog.Say ();
    cat.Say ();

    return EXIT_SUCCESS;
}
