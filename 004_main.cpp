// Class template specialization.
// Compile and run:
// $ g++ -Wall -Wextra -std=c++11 004_main.cpp -o 004_main
// $ ./004_main
// $ echo $?

template <typename T>
class Counter
{
    public:
        Counter      (T);
        bool Update  (T);
        T Current    () const {return count;}

    private:
        T count;
};

template <typename T>
Counter <T>::Counter (T init)
    : count {init < T (0) ? T (0) : init}
{
}

template <typename T>
bool Counter <T>::Update (T diff) 
{
    if (diff < T (0) )
        return false;
 
    count += diff;
    return true;
}

template <>
Counter <unsigned>::Counter (unsigned init)
    : count {init}
{
}

template <>
bool Counter <unsigned>::Update (unsigned diff) 
{
    count += diff;
    return true;
}

int main (int, char **)
{
    int res = 0;
    {
        Counter <double> c (-1);
        c.Update (1);
        c.Update (0);
        c.Update (0);
        c.Update (1);
        res += c.Current ();
    }

    {
        Counter <unsigned> c (0);
        c.Update (1);
        c.Update (0);
        c.Update (0);
        c.Update (1);
        res += c.Current ();
    }

    return res;
}
