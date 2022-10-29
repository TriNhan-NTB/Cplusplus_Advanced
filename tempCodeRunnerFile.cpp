#include <iostream>

using namespace std;

void test(int&& a)
{
    a++;
}

int main()
{
    int num;
    int&& a = 7;
    test(std::move(a));
    cout << a;
    return 0;
}