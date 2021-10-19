//
// Created by lossv on 2021/10/18.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int subResult;
        map<int, int> mMap;
        for(int i = 0; i < nums.size(); ++i)
        {
            subResult = target - nums[i];
            if(mMap.find(subResult) != mMap.end())
            {
                return {i, mMap[subResult]};
            }
            mMap[nums[i]]= i;
        }
        return {};
    }
};

int main()
{
    vector<int> ilist = {3, 3, 4};
    int iTarget = 6;
    Solution solution;
    auto res = solution.twoSum(ilist, iTarget);

    cout << res[0] << " " << res[1] << endl;

    return 0;
}