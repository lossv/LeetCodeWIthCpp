//
// Created by 觉而不绝 on 2023/4/23.
//

#include "comm.h"

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if(numRows == 1) return s;
        int size = s.length();
        int i = 0;
        int downFLag = true;
        int rowCount = 0;
        vector<string> floorList(numRows, "");
        string result = "";
        while (i < size)
        {
            if (downFLag)
            {
                floorList[rowCount++] += s[i];
                if(rowCount == numRows)
                {
                    --rowCount;
                    downFLag = false;
                }
            }
            else
            {
                floorList[--rowCount] += s[i];
                if(!rowCount)
                {
                    ++rowCount;
                    downFLag = true;
                }
            }

            ++i;
        }

        for(auto &str: floorList)
        {
            result += str;
        }

        return result;
    }
};
//PAHNAPLSIIGYIR



int main()
{
    string s = "AB";
    int n = 2;
    Solution solution;
    cout << solution.convert(s, n);
    return 0;
}