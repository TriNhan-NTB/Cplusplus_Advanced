/**
 * @file std_condition_variable.cpp
 * @author nhannguyen (nhannguyen482000@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-29
 * @ref: https://en.cppreference.com/w/cpp/thread/condition_variable
 * 
*/

/*
The condition_variable class is a synchronization primitive used with a std::mutex to block one or more threads until another thread both modifies a shared variable (the condition) and notifies the condition_variable.
The thread that intends to modify the shared variable must:
    Acquire a std::mutex (typically via std::lock_guard)
    Modify the shared variable while the lock is owned
    Call notify_one or notify_all on the std::condition_variable (can be done after releasing the lock)
*/

#include <mutex>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <condition_variable>

using namespace std;

std::mutex m;
std::condition_variable check;

void supportFunc1()
{
    cout << "supportFuct1 start sleep" << endl;
    sleep(5);
    check.notify_one();
}

void func1(int &n1, int &compare)
{
    std::unique_lock<std::mutex> lock(m);
    if(n1 == compare)
    {
        cout << "Wait notify" << endl;
        check.wait(lock);
        cout << "Finish wait" << endl;
    }
    cout << "Do something here" << endl;
}

int main()
{
    int n1{5};
    int compare1{5};

    std::thread t1{func1, std::ref(n1), std::ref(compare1)};
    std::thread t2{supportFunc1};
 
    t1.join();
    t2.join();   
}

/*output*/

/*
Wait notify
supportFuct1 start sleep
Finish wait
Do something here
*/