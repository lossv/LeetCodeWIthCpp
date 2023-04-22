//
// Created by 觉而不绝 on 2023/4/23.
//

#include "comm.h"

using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int size = citations.size(), result = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            if (citations[i] >= size - i)
            {
                result = max(result, size - i);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;

    vector<int> nums{100, 1};
    cout << solution.hIndex(nums);

    return 0;
}