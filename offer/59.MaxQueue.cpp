//
// Created by 觉而不绝 on 2023/3/17.
//
#include "comm.h"

using namespace std;

class MaxQueue
{
public:
    MaxQueue()
    {

    }

    int max_value()
    {
        if(maxValues.empty())
        {
            return -1;
        }
        return maxValues.front();
    }

    void push_back(int value)
    {
        while (!maxValues.empty() && maxValues.back() < value)
            maxValues.pop_back();

        maxValues.push_back(value);
        data.push(value);
    }

    int pop_front()
    {
        if(data.empty())
            return -1;

        int curMaxValue = maxValues.front();
        int curFrontValue = data.front();
        if(curMaxValue == curFrontValue)
            maxValues.pop_front();

        data.pop();
        return curFrontValue;

    }

private:
    queue<int> data;
    deque<int> maxValues;
};
