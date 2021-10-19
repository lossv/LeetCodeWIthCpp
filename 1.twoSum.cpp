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
        vector<int> res;
        map<int, vector<int> > mMap;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(mMap.find(nums[i]) == mMap.end())
                mMap.insert(pair<int, vector<int> >(nums[i], { i }));
            else
                mMap[nums[i]].push_back(i);
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            int subResult = target - nums[i];
            if(mMap.find(subResult) != mMap.end())
            {
                if(mMap[subResult].size() == 1 and mMap[subResult][0] == i)
                    continue;
                res.push_back(i);
                if(subResult == nums[i])
                    res.push_back(mMap[subResult][1]);
                else
                    res.push_back(mMap[subResult][0]);
                break;
            }
        }
        return res;
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