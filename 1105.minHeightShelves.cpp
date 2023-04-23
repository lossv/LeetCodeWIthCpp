#include "comm.h"

using namespace std;

class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int size = books.size();
        vector<int> dp(size + 1, INT32_MAX);

        dp[0] = 0;

        for(int i = 0; i <= size; ++i)
        {
            int w = 0, h = 0;
            for(int j = i; j >= 1; --j)
            {
                w += books[j - 1][0];
                if(w > shelfWidth)
                {
                    break;
                }

                h = max(h, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + h);
            }
        }


        return dp[size];
    }
};
int main()
{

    return 0;
}