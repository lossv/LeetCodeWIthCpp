//
// Created by lossv on 2022/7/29.
//

#include <vector>
#include <iostream>

using std::vector;


class Solution
{
public:

    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        return isRightTriangle(p1, p2, p3) && isRightTriangle(p1, p2, p4) && isRightTriangle(p1, p3, p4) &&
               isRightTriangle(p2, p3, p4);
    }


    bool isRightTriangle(vector<int> &p1, vector<int> &p2, vector<int> &p3)
    {
        int d1 = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        int d2 = (p2[0] - p3[0]) * (p2[0] - p3[0]) + (p2[1] - p3[1]) * (p2[1] - p3[1]);
        int d3 = (p3[0] - p1[0]) * (p3[0] - p1[0]) + (p3[1] - p1[1]) * (p3[1] - p1[1]);
        if (d1 > d2 && d2 == d3 && d2 + d3 == d1 ||
            d2 > d1 && d1 == d3 && d1 + d3 == d2 ||
            d3 > d1 && d1 == d2 && d1 + d2 == d3)
        {
            return true;
        }
        return false;
    }
};


int main()
{
    Solution solution;
//    std::cout << solution.isRightTriangle()
}