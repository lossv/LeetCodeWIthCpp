//
// Created by lossv on 2021/11/9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        long sumRet = 0;
        int value = 1;
        for (auto &item: nums)
        {
            sumRet += item - value++;
        }
        return abs(sumRet);
    }
};

int main()
{
    vector<int> num = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    Solution solution;
    cout << solution.missingNumber(num);
    return 0;
}