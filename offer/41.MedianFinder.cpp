//
// Created by 觉而不绝 on 2023/3/15.
//
#include "comm.h"

using namespace std;


class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {

    }

    void addNum(int num)
    {
        int left = 0, right = data.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (data[mid] < num)
                left = mid + 1;
            else
                right = mid - 1;
        }

        data.insert(data.begin() + left, num);
    }

    double findMedian()
    {
        if (data.size() % 2 == 0)
        {
            return (data[data.size() / 2] + data[(data.size() / 2) - 1]) / 2.0;
        }

        return data[data.size() / 2];

    }

private:
    vector<int> data;
};


int main()
{
    MedianFinder finder;

    finder.addNum(6);
    cout << finder.findMedian() << endl;
    finder.addNum(10);
    cout << finder.findMedian() << endl;

    finder.addNum(2);
    cout << finder.findMedian() << endl;

    finder.addNum(6);
    cout << finder.findMedian() << endl;

    finder.addNum(5);
    cout << finder.findMedian() << endl;

    finder.addNum(0);
    cout << finder.findMedian() << endl;

    finder.addNum(6);
    cout << finder.findMedian() << endl;

    finder.addNum(3);
    cout << finder.findMedian() << endl;

    finder.addNum(1);
    cout << finder.findMedian() << endl;

    finder.addNum(0);
    cout << finder.findMedian() << endl;

    finder.addNum(0);
    cout << finder.findMedian() << endl;

    return 0;
}