//
// Created by lossv on 2022/1/25.
//

#include <functional>
#include <mutex>

using std::function;
using std::mutex;

class ZeroEvenOdd
{
private:
    int n;
    mutex m1, m2, m3;
public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
        m1.lock();
        m2.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        for (int i = 0; i < n; ++i)
        {
            m3.lock();
            printNumber(0);
            if(i % 2 == 0)
            {
                m2.unlock();
            }
            else
            {
                m1.unlock();
            }
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2)
        {
            m1.lock();
            printNumber(i);
            m3.unlock();
        }
    }

    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2)
        {
            m2.lock();
            printNumber(i);
            m3.unlock();
        }
    }
};

int main()
{

    return 0;
}