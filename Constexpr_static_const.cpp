/*
constexpr
    - part of declaration but not part of data type
    - used in a similar way as static or inline
    - sometimes adds const as a side affect

    - asks the complier to evaluate and run code at compile
    - when a value is computed at compile time instead of run time, it helps your program run faster and use less memory.
    - constexpr function can call only other constexpr function not simple function.
*/

#include <iostream>
using namespace std;

class Test
{
    public:
        constexpr void inc(int &a)
        {
            a++;
        }
};

int main()
{
    return 0;
}