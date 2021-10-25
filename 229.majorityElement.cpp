//
// Created by lossv on 2021/10/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> cnt;

        for (auto &v: nums) {
            cnt[v]++;
        }
        for (auto &v: cnt) {
            if (v.second > n / 3) {
                ans.push_back(v.first);
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {3, 2, 3};
    Solution solution;
    auto result = solution.majorityElement(nums);
    for (auto i: result)
        cout << i << " ";
    return 0;
}