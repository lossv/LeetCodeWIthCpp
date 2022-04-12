//
// Created by lossv on 2022/4/12.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        vector<int> res(2, 0);
        res[0] = 1;
        for (char w: s)
        {
            int v = widths[w - 'a'];
            res[1] += v;
            if (res[1] > 100) ++res[0], res[1] = v;
        }

        return res;
    }
};


int main()
{

}