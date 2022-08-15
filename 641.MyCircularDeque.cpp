//
// Created by lossv on 2022/8/15.
//

#include <deque>

using namespace std;

class MyCircularDeque
{
public:
    MyCircularDeque(int k)
    {
        m_len = k;
        deque1.clear();
    }

    bool insertFront(int value)
    {
        if (deque1.size() == m_len)
            return false;
        deque1.push_front(value);

        return true;
    }

    bool insertLast(int value)
    {
        if (deque1.size() == m_len)
            return false;

        deque1.push_back(value);

        return true;
    }

    bool deleteFront()
    {
        if (deque1.empty())
            return false;

        deque1.pop_front();

        return true;
    }

    bool deleteLast()
    {
        if (deque1.empty())
            return false;

        deque1.pop_back();

        return true;
    }

    int getFront()
    {
        if (deque1.empty())
            return -1;

        return deque1.front();
    }

    int getRear()
    {
        if (deque1.empty())
            return -1;

        return deque1.back();
    }

    bool isEmpty()
    {
        return deque1.empty();
    }

    bool isFull()
    {
        return deque1.size() == m_len;
    }

private:
    int m_len;
    deque<int> deque1;
};

int main()
{
    MyCircularDeque circularDeque = MyCircularDeque(3); // 设置容量大小为3
    circularDeque.insertLast(1);			        // 返回 true
    circularDeque.insertLast(2);			        // 返回 true
    circularDeque.insertFront(3);			        // 返回 true
    circularDeque.insertFront(4);			        // 已经满了，返回 false
    circularDeque.getRear();  				// 返回 2
    circularDeque.isFull();				        // 返回 true
    circularDeque.deleteLast();			        // 返回 true
    circularDeque.insertFront(4);			        // 返回 true
    circularDeque.getFront();				// 返回 4


    return 0;
}