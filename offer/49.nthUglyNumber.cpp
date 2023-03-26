//
// Created by 觉而不绝 on 2023/3/18.
//

#include "comm.h"

using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int a = 0, b = 0, c = 0;
        vector<int> record(n, 0);

        record[0] = 1;

        for(int i = 1; i < n; ++i)
        {
            int tmpAValue = record[a] * 2;
            int tmpBValue = record[b] * 3;
            int tmpCValue = record[c] * 5;
            int tmpValue = min({tmpAValue, tmpBValue, tmpCValue});
            record[i] = tmpValue;

            if (tmpValue == tmpAValue)
                ++a;
            if (tmpValue == tmpBValue)
                ++b;
            if (tmpValue == tmpCValue)
                ++c;

        }

        return record[n - 1];

    }
};


int main()
{
    Solution solution;
    int n = 50;
    cout << solution.nthUglyNumber(n);
    return 0;
}