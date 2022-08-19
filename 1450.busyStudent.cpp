//
// Created by dmlt on 2022/8/19.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int busyStudent(const vector<int> &startTime, const vector<int> &endTime, int queryTime)
    {
        int cnt = 0;
        for (int i = 0; i < startTime.size(); ++i)
        {
            if (startTime[i] <= queryTime && queryTime <= endTime[i])
                ++cnt;
        }

        return cnt;
    }
};


int main()
{
    auto startTime = {1, 2, 3};
    auto endTime = {3, 2, 7};
    auto queryTime = 4;
    Solution solution;

    cout << solution.busyStudent(startTime, endTime, queryTime);

    return 0;
}