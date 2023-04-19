#include "comm.h"

using namespace std;

//class Solution
//{
//public:
//    int maxSumAfterPartitioning(vector<int> &arr, int k)
//    {
//        maxValue = 0;
//
//        dfs(arr, k, -1, 0);
//
//        return maxValue;
//    }
//
//    void dfs(vector<int> &arr, int k, int curIndex, int curValue)
//    {
//        if (curIndex == arr.size() - 1)
//        {
//            maxValue = std::max(maxValue, curValue);
//            return;
//        }
//
//        int tmpValue = -1;
//        for (int i = 1; i <= k && curIndex + i < int(arr.size()); ++i)
//        {
//            tmpValue = std::max(tmpValue, arr[curIndex + i]);
//            dfs(arr, k, curIndex + i, curValue + tmpValue * i);
//        }
//    }
//
//private:
//    int maxValue;
//};

class Solution
{
public:
    using ll = long long;

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int maxValue = arr[i - 1];
            for (int j = i - 1; j >= 0 && j >= i - k; j--)
            {
                d[i] = max(d[i], d[j] + maxValue * (i - j));
                if (j > 0)
                {
                    maxValue = max(maxValue, arr[j - 1]);
                }
            }
        }
        return d[n];
    }
};


int main()
{
    Solution solution;
    vector<int> arr{1, 15, 7, 9, 2, 5, 10};

    cout << solution.maxSumAfterPartitioning(arr, 3);

    return 0;
}