//
// Created by lossv on 2022/8/11.
//

#include <vector>
#include <cstdlib>
#include <cstdint>

using std::vector;

class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int sum = 0, minVal = INT32_MAX;
        for (auto &item: nums)
        {
            sum += item;
            minVal = std::min(minVal, sum);
        }

        return minVal >= 1 ? 1 : abs(minVal) + 1;
    }
};

int main()
{

    return 0;
}