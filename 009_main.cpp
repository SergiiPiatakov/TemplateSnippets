// Templates and inheritance.
// Compile and run:
// $ g++ -Wall -Wextra -Wno-unused-variable 009_main.cpp -o 009_main
// $ ./009_main
// $ echo $?

template <typename T>
struct Wrapper
{
};

struct Base
{
};

struct Derived : Base
{
};

void Processing (Base &)
{
    // Some stuff here...
}

void ProcessingWrapper (Wrapper <Base> &)
{
    // Some stuff here...
}

int main (int argc, char **)
{
    Base              b;
    Derived           d;
    Wrapper <Base>    bw;
    Wrapper <Derived> dw;

    Processing          (b);
    Processing          (d);
    //Processing        (bw); Error.
    //Processing        (dw); Error.
    ProcessingWrapper   (bw);
    //ProcessingWrapper (dw); Error.

    return argc - 1;
}
