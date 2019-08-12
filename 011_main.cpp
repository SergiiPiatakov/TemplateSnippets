// Function template alternative (macro).
// Compile and run:
// $ g++ -Wall -Wextra 011_main.cpp -o 011_main
// $ ./011_main
// $ echo $?

// Macro definition:
#define Max(a,b) \
	( ( (a) > (b) ) ? (a) : (b) )

int main (int argc, char **)
{
    int x = 42;
    int y = argc;
    int m = 0;

    // Using of the macro.
    m = Max (x, y);

    return m;
}
