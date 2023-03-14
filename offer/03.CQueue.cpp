//
// Created by 觉而不绝 on 2023/3/13.
//
#include "comm.h"

using namespace std;

class CQueue
{
public:
    CQueue()
    {

    }

    void appendTail(int value)
    {
        stackIn.push(value);
    }

    int deleteHead()
    {
        while (!stackIn.empty())
        {
            stackOut.push(stackIn.top());
            stackIn.pop();
        }

        if(!stackOut.empty())
        {
            int value = stackOut.top();
            stackOut.pop();
            while (!stackOut.empty())
            {
                stackIn.push(stackOut.top());
                stackOut.pop();
            }
            return value;
        }

        return -1;
    }
private:
    stack<int> stackIn;
    stack<int> stackOut;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */