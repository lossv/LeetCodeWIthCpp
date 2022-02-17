//
// Created by 觉而不绝 on 2022/2/17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double knightProbability(int N, int K, int r, int c)
    {
        //dp[row][col][j]用于存储在row行，col列走j步不出界的概率
        vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K + 1, 0)));
        vector<pair<int, int>> directions = {
                {1,  2},
                {-1, 2},
                {1,  -2},
                {-1, -2},
                {2,  1},
                {-2, 1},
                {2,  -1},
                {-2, -1}
        };//八个方向
        //初始化，当k == 0时，此时不能再移动了，将永远停在此地，所以不出界的概率为1.0
        for (int row = 0; row < N; ++row)
        {
            for (int col = 0; col < N; ++col)
            {
                dp[row][col][0] = 1.0;
            }
        }
        //开始动态规划
        for (int k = 1; k <= K; ++k)
        {//自底向上，逐渐增加步数
            //下面的两个for是穷举起始点
            for (int row = 0; row < N; ++row)
            {
                for (int col = 0; col < N; ++col)
                {
                    double tempRes = 0;
                    //统计八个方向走k - 1步不出界的概率之和
                    for (auto &direction: directions)
                    {
                        int nextRow = row + direction.first;
                        int nextCol = col + direction.second;
                        if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= N)
                        {//出界
                            continue;
                        } else
                        {
                            tempRes += dp[nextRow][nextCol][k - 1];
                        }
                    }
                    dp[row][col][k] += tempRes / 8;//最后除8，因为当前重八步中选择不出界也有概率
                }
            }
        }
        return dp[r][c][K];
    }
};

int main()
{
    Solution solution;
    return 0;
}