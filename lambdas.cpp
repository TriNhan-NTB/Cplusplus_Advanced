/**
 * @file lambdas.cpp
 * @author nhannguyen (nhannguyen482000@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-30
 * 
*/

/*
syntax to declare an object which can be invoked
can be assigned to a variable
data type of the variable should be auto
syntax for a lambda expression consists of specific puntuation [](){}
[capture clause](paramater list)->return type{body};

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct myData
{
    int x=0;
    int y=0;
};

template<class T, class BinaryOperation>
T IncXY(T data, BinaryOperation op)
{
    return op(data.x, data.y);
}

int main()
{
    myData data1;
    auto rt = IncXY(data1, [&](int x, int y){
        myData newData;
        newData.x = ++x;
        newData.y = ++y;
        return newData;
    });

    cout << "x = " << rt.x << endl;
    cout << "y = " << rt.y << endl;

    return 0;
}

/*output*/

/*
x = 1
y = 1
*/