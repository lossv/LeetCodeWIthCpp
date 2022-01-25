//
// Created by lossv on 2022/1/25.
//

#include <functional>
#include <thread>
#include <mutex>

using namespace std;

class Foo
{

private:
    int wait;
public:

    Foo()
    {
        wait = 0;
    }

    void first(function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        wait = 1;
    }

    void second(function<void()> printSecond)
    {
        while (wait != 1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        wait = 2;
    }

    void third(function<void()> printThird)
    {
        while (wait != 2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

class Foo2
{

private:
    std::mutex m3, m2;
public:

    Foo2()
    {
        m2.lock();
        m3.lock();
    }

    void first(function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m2.unlock();
    }

    void second(function<void()> printSecond)
    {
        // printSecond() outputs "second". Do not change or remove this line.
        m2.lock();
        printSecond();
        m3.unlock();
    }

    void third(function<void()> printThird)
    {

        // printThird() outputs "third". Do not change or remove this line.
        m3.lock();
        printThird();
        m3.unlock();
    }
};