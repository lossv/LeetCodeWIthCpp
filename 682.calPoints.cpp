//
// Created by 觉而不绝 on 2022/3/26.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        vector<int> nums;
        for (auto &item: ops)
        {
            if (item[0] == '+')
            {
                nums.__emplace_back(nums[nums.size() - 1] + nums[nums.size() - 2]);
            }
            else if (item[0] == 'D')
            {
                nums.__emplace_back(nums[nums.size() - 1] * 2);
            }
            else if (item[0] == 'C')
            {
                nums.erase(nums.end() - 1);
            }
            else
            {
                nums.__emplace_back(stoi(item));
            }
        }
        int res = 0;
//        std::for_each(nums.begin(), nums.end(), [&](int n)
//        {
//            res += n;
//        });
        auto fun = [&](){
            for(auto &item : nums)
                res += item;
            return res;
        };
        return fun();


    }
};

int main()
{
    vector<string> list = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    Solution solution;
    cout << solution.calPoints(list) << endl;
    return 0;
}