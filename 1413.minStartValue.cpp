//
// Created by lossv on 2022/8/11.
//

#include <vector>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int sum = 0, minVal = INT32_MAX;
        for (auto &item: nums)
        {
            sum += item;
            minVal = std::min(minVal, sum);
        }

        return minVal >= 1 ? 1 : abs(minVal) + 1;
    }
};

int globalvar = 20;

int &foo()
{
    return globalvar;
}

int main()
{
//    string a = "aaaa";
//
//    auto c = static_cast<string&&>(a);
//    auto b = std::move(a);

    foo() = 10;
    std::cout << globalvar << std::endl;

    return 0;
}