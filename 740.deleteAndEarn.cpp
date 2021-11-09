//
// Created by lossv on 2021/10/26.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        map<int, int> mMap;
        set<int> mSet;
        for (int & num : nums)
            mMap[num] += num;
        
        return 0;
    }
};

int main()
{
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    Solution solution;
    cout << solution.deleteAndEarn(nums);
    return 0;
}
