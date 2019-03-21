// Variadic templates.
// Compile and run:
// $ g++ -Wall -Wextra -std=c++11 005_main.cpp -o 005_main
// $ ./005_main
// $ echo $?

template <typename T>
T Sum (T x)
{
    return x;
}

template <typename T, typename... U>
T Sum (T x, U... y)
{
    return x + Sum (y...);
};

int main (int, char **)
{
    return Sum (1, 2, 3, 4);
}
