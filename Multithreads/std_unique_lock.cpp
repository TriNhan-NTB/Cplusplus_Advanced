/**
 * @file std_unique_lock.cpp
 * @author nhannguyen (nhannguyen482000@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-29
 * 
*/

/*
When the unique_lock is constructed it will lock the mutex, and it gets destructed it will unlock the mutex. 
If a exceptions is thrown, the std::unique_lock destructer will be called and so the mutex will be unlocked.
*/

#include <mutex>
#include <thread>
#include <iostream>
#include <unistd.h>

using namespace std;

std::mutex m;
int index_thread = 1;

void func1(int &n1, int &compare)
{
    {
        std::unique_lock<std::mutex> lock(m);
        while(n1>compare)
        {
            cout << "Fucn1: n = " << n1 << " Index Thread: " << index_thread << endl;
            n1--;
            sleep(1);
        }
    }
    cout << "Out Block of Func1" << endl;
    index_thread++;
}

int main()
{
    int n1{10};
    int compare1{5};
    int compare2{0};

    std::thread t1{func1, std::ref(n1), std::ref(compare1)};
    std::thread t2{func1, std::ref(n1), std::ref(compare2)};
 
    t1.join();
    t2.join();   
}

/*output*/

/*
Fucn1: n = 10 Index Thread: 1
Fucn1: n = 9 Index Thread: 1
Fucn1: n = 8 Index Thread: 1
Fucn1: n = 7 Index Thread: 1
Fucn1: n = 6 Index Thread: 1
Out Block of Func1
Fucn1: n = 5 Index Thread: 2
Fucn1: n = 4 Index Thread: 2
Fucn1: n = 3 Index Thread: 2
Fucn1: n = 2 Index Thread: 2
Fucn1: n = 1 Index Thread: 2
Out Block of Func1
*/