// Class template.
// Compile and run:
// $ g++ -Wall -Wextra -std=c++11 003_main.cpp -o 003_main
// $ ./003_main
// $ echo $?

template <typename T>
struct Serializer
{
    Serializer (T v)
        : value {v}
    {
    }

    char Data (unsigned);

    union
    {
        T value;
        char data [sizeof (T)];
    };
};

template <typename T>
char Serializer <T>::Data (unsigned i)
{
    if (i < sizeof (T) )
        return data [i];
    return 0;
}

class Person
{
    public:
        Person (unsigned char a)
            : age {a}
        {
        }

        unsigned char GetAge () const {return 18;}
        
    protected:
        unsigned char age;
};

int main (int, char **)
{
    Person shy (42);
    
    // What is your age?
    shy.GetAge ();
    // Realy?
    // shy.age;
    // error: ‘unsigned char Person::age’ is protected
    // OK, I'll check it in other way.
    Serializer <Person> x (shy);
    //x.data [0];

    return x.Data (0);
}
