//
// Created by lossv on 2021/10/25.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if(matrix.size() == 0)
            return false;
        int m = 0;
        int n = matrix[0].size() - 1;
        while (m < matrix.size() && n >= 0)
        {
            if(matrix[m][n] == target)
                return true;
            else if(matrix[m][n] > target)
                n--;
            else
                m++;
        }
        return false;
    }
};

int main()
{

    return 0;
}