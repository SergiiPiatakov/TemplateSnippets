// Containers and Algorithms.
// Compile and run:
// $ g++ -Wall -Wextra -std=c++11 010_main.cpp -o 010_main
// $ ./010_main
// $ echo $?

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdlib>

template <int N>
bool IsNoReminder (int x)
{
    return !(x % N);
}

int main (int, char **)
{
    std::vector <int> data {235, 51, 5566};

    auto checkAndPrint = [](std::vector <int> & data, std::function <bool(int)> pred) {
        std::vector <int>::iterator pos = data.end ();
        pos = std::find_if (data.begin (), data.end (), pred);
        if (pos != data.end () )
            std::cout << * pos << std::endl;
        else
            std::cout << "-" << std::endl;
    };

    checkAndPrint (data, IsNoReminder <5>);
    checkAndPrint (data, IsNoReminder <3>);
    checkAndPrint (data, IsNoReminder <2>);
    checkAndPrint (data, IsNoReminder <7>);

    return EXIT_SUCCESS;
}
