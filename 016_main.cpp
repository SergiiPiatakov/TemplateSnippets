// CRTP.
// Compile and run:
// $ g++ -Wall -Wextra 016_main.cpp -o 016_main
// $ ./016_main

#include <string>
#include <iostream>
#include <cstdlib>

template <typename T>
struct Animal
{
    void Say () {std::cout << static_cast <T &>(* this).Voice () << std::endl;}
};

struct Dog : Animal <Dog>
{
    std::string Voice () {return "Woof.";}
};

struct Cat : Animal <Cat>
{
    std::string Voice () {return "OUUUAAA!";}
};

int main (int, char **)
{
    Dog dog;
    Cat cat;

    dog.Say ();
    cat.Say ();

    return EXIT_SUCCESS;
}
