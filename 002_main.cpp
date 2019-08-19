// Function template overloading.
// Compile and run:
// $ g++ -Wall -Wextra 002_main.cpp -o 002_main
// $ ./002_main
// $ echo $?

template <typename T>
void Swap (T & a, T & b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
void Swap (T * const a, T * const b)
{
    Swap (* a, * b);
}

int main (int argc, char **)
{
    int a = 0;
    int b = 1;
    int * /*const*/ c = new int (2);
    int * /*const*/ d = new int (3);

    // Before:
    //  0  <->  1
    //  ^       ^
    //  |       |
    //  a       b
    //
    // After:
    //  1       0
    //  ^       ^
    //  |       |
    //  a       b
    Swap (a, b);
    
    // Before:
    //  2       3
    //  ^       ^
    //  |       |
    // 0xa <-> 0xe
    //  ^       ^
    //  |       |
    //  c       d
    //
    // After:
    //  2       3
    //     \ /
    //      x 
    //     / `
    // 0xe     0xa
    //  ^       ^
    //  |       |
    //  c       d

    // Or.
    // Before:
    //  2  <->  3
    //  ^       ^
    //  |       |
    // 0xa     0xe
    //  ^       ^
    //  |       |
    //  c       d
    //
    // After:
    //  3       2
    //  ^       ^
    //  |       |   
    // 0xa     0xe
    //  ^       ^
    //  |       |
    //  c       d
    Swap (c, d);

    return argc - 1;
}
