//
// Created by lossv on 2021/10/20.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int totalLen = nums1.size() + nums1.size();
        int midLen = totalLen / 2;
        int i = 0, j = 0;
        while (true)
        {
            if(i + j == midLen)
                return midLen;

        }
    }
};

int main()
{

    return 0;
}