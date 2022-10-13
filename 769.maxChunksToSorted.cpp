//
// Created by dmlt on 2022/10/13.
//

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int result = 0, max_val = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            max_val = max(max_val, arr[i]);
            if (max_val == i)
            {
                ++result;
            }
        }

        return result;
    }

};


int main()
{
    return 0;
}