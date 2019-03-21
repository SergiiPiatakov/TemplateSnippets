// Template instantiation.
// Compile and run:
// $ g++ -Wall -Wextra 006_main.cpp -o 006_main
// $ ./006_main
// $ echo $?

struct Usual
{
    int GetSomethingUsual () {return 1;}
};

struct Special
{
    int GetSomethingUsual   () {return 1;}
    int GetSomethingSpecial () {return 2;}
};

template <typename T>
struct Collector
{
    int CollectUsual   (T x) {return x.GetSomethingUsual   ();}
    int CollectSpecial (T x) {return x.GetSomethingUsuali  ()
                                   + x.GetSomethingSpecial ();}
};

int main (int, char **)
{
    Usual u;
    Collector <Usual> c;
    return c.CollectUsual (u) /*+ c.CollectSpecial (u)*/;
}
