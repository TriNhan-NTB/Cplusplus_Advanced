/**
 * @file mutex_lock.cpp
 * @author nhannguyen (nhannguyen482000@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-29
 * 
*/

/*
The mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads.
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

std::mutex m;//you can use std::lock_guard if you want to be exception safe
int i = 0;

void Call() 
{
    m.lock();
      std::cout << i << " Hello Wife" << std::endl;
      sleep(2);
      std::cout << i << " Get Out" << std::endl;
      i++;
    m.unlock();
}

int main() 
{
    std::thread stupidman1(Call);
    std::thread stupidman2(Call);
    std::thread stupidman3(Call);

    stupidman1.join();
    stupidman2.join();
    stupidman3.join();
    return 0;
}