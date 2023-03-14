//
// Created by 觉而不绝 on 2023/3/13.
//
#include "comm.h"

class MinStack
{

#define N 20000
public:
    /** initialize your data structure here. */
    MinStack()
    {
        stackIndex = 0;

    }

    void push(int x)
    {
        if(stackIndex < N)
        {
            stackArr[stackIndex] = x;
            if(stackIndex == 0)
            {
                minList[stackIndex] = x;
            }
            else
            {
                minList[stackIndex] = std::min(minList[stackIndex - 1], x);
            }

            ++stackIndex;
        }
    }

    void pop()
    {
        if(stackIndex > 0)
        {
            stackArr[--stackIndex];
        }
    }

    int top()
    {
        if(stackIndex > 0)
        {
            return stackArr[stackIndex - 1];
        }

        return -1;
    }

    int min()
    {
        return minList[stackIndex - 1];
    }

private:
    int stackArr[N];
    int minList[N];

    int stackIndex;
};