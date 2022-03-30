//
// Created by 觉而不绝 on 2022/2/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> ans;
        for (int i = 0; i < arr.size(); ++i)
        {
            auto m = max_element(arr.begin(), arr.end() - i);
            if (m == arr.end() - i - 1) continue;
            reverse(arr.begin(), m + 1);
            ans.push_back(m - arr.begin() + 1);
            reverse(arr.begin(), arr.end() - i);
            ans.push_back(arr.end() - i - arr.begin());
        }
        return ans;
    }
};

int main()
{

    return 0;
}