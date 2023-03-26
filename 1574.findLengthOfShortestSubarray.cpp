//
// Created by 觉而不绝 on 2023/3/25.
//
#include "comm.h"

using namespace std;

class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        vector<int> front, rear;
        front.push_back(arr[0]);
        rear.push_back(arr.back());
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] <= arr[i + 1]) front.push_back(arr[i + 1]);
            else break;
        }
        for (int i = arr.size() - 1; i > 0; i--)
        {
            if (arr[i] >= arr[i - 1]) rear.push_back(arr[i - 1]);
            else break;
        }
        if (front.size() == arr.size()) return 0;
        reverse(rear.begin(), rear.end());
        int ans = 0;
        int n = front.size(), m = rear.size(), i = 0, j = 0;
        while (i < n && j < m)
        {
            if (front[i] <= rear[j])
            {
                ans = max(ans, (m - j) + (i + 1));
                ++i;
            }
            else
            {
                ++j;
            }
        }
        return arr.size() - max(max(n, m), ans);
    }
};


int main()
{
    Solution solution;
    vector<int> arr{1, 2, 3, 10, 4, 2, 3, 5};
    cout << solution.findLengthOfShortestSubarray(arr);
    return 0;
}