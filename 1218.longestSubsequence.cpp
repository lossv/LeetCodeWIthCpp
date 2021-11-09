//
// Created by lossv on 2021/11/5.
//
#include <iostream>
#include <vector>


using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        int iMax = 1;
        int iTmp = 1;
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i] - arr[i - 1] == difference)
                iTmp++;
            else
            {
                max(iMax, iTmp);
                iTmp = 1;
            }
        }
        return max(iMax, iTmp);;
    }
};


int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int iDifference = 1;
    Solution solution;
    cout << solution.longestSubsequence(arr, iDifference);
    return 0;
}