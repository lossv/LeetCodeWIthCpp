//
// Created by lossv on 2022/7/19.
//

#include <map>

using namespace std;


class MyCalendarTwo
{
public:
    map<int, int> m_map;

    MyCalendarTwo()
    {

    }

    bool book(int start, int end)
    {
        int cnt = 0;
        m_map[start]++;
        m_map[end]--;
        for (const auto &[_, t]: m_map)
        {
            cnt += t;
            if (cnt > 2)
            {
                m_map[start]--;
                m_map[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 * MyCalendar();

 MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true


 */

int main()
{
    MyCalendarTwo MyCalendar;
    MyCalendar.book(10, 20); // returns true
    MyCalendar.book(50, 60); // returns true
    MyCalendar.book(10, 40); // returns true
    MyCalendar.book(5, 15); // returns false
    MyCalendar.book(5, 10); // returns true
    MyCalendar.book(25, 55); // returns true
    return 0;
}