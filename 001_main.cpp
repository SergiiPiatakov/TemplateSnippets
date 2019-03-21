// Function template.
// Compile and run:
// $ g++ -Wall -Wextra 001_main.cpp -o 001_main
// $ ./001_main
// $ echo $?

// Template definition:
// - `template`         - keyword;
// - `<` & `>`          - list of template parameters;
// - `typename T`       - type template parameter;
// - `T Max (T a, T b)` - template function definition.
template <typename T>
T Max (T a, T b)
{
    if (a > b)
        return a;
    return b;
}

int main (int argc, char **)
{
    int x = 42;
    int y = argc;
    int m = 0;

    // Using of the template.
    m = Max <int> (x, y);
    // Other variants of using:
    // OK  - Max <> (x, y);  // Successful argument deduction.
    // OK  - Max (x, y);     // Successful argument deduction.
    // Bad - Max (x, 4.2);   // Failed argument deduction.
    // OK  - Max (x, static_cast <int> (4.2) );
    // OK  - Max <int> (x, 4.2);

    return m;
}
