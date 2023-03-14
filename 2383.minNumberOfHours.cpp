//
// Created by 觉而不绝 on 2023/3/13.
//
#include "comm/comm.h"
#include  <numeric>

using namespace std;


class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int train = 0;
        int useEnergy = 0;
        int exp = initialExperience;
        for (int i = 0; i < energy.size(); ++i)
        {
            useEnergy += energy[i];
            if (exp <= experience[i])
            {
                int addValue = experience[i] - exp + 1;
                train += addValue;
                exp += addValue;
            }
            exp += experience[i];
        }

        if (useEnergy >= initialEnergy)
        {
            train += useEnergy - initialEnergy + 1;
        }

        return train;
    }
};

//class Solution
//{
//public:
//    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
//    {
//        int s = accumulate(energy.begin(), energy.end(), 0);
//        int ans = max(0, s - initialEnergy + 1);
//        for (int x: experience)
//        {
//            if (initialExperience <= x)
//            {
//                ans += x - initialExperience + 1;
//                initialExperience = x + 1;
//            }
//            initialExperience += x;
//        }
//        return ans;
//    }
//};


int main()
{
    Solution solution;
    int energy = 5;
    int exp = 1;
    vector<int> engList = {1, 3, 3};
    vector<int> expList = {1, 3, 7};
    cout << solution.minNumberOfHours(energy, exp, engList, expList);
    return 0;
}