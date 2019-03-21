// Function objects.
// Compile and run:
// $ g++ -Wall -Wextra -std=c++11 008_main.cpp -o 008_main
// $ ./008_main
// $ echo $?

template <typename T>
struct Analyzer
{
    void operator ()(T x)
    {
        ++cnt;
        sum += x;
        avg  = sum / cnt;
    }

    T           sum {T (0)};
    T           avg {T (0)};
    unsigned    cnt {0};
};

int main (int, char **)
{
    constexpr unsigned size {5};

    float dataSetA [size] = {1., 2, 3.0, 42.f, -7};
    float dataSetB [size] = {0., 0, 0.0, 24.f, -1};
    Analyzer <float> a;

    for (unsigned i = 0; i < size; ++i) {
        a (dataSetA [i]);
    }
    for (unsigned i = 0; i < size; ++i) {
        a (dataSetB [i]);
    }

    return a.cnt;
}
