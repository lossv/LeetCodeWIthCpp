//
// Created by lossv on 2022/7/20.
//

#include <vector>
#include <iostream>

using namespace std;

template<class T>
void printVector(vector<vector<T>> &grid)
{
    for (auto &items: grid)
    {
        for (auto &item: items)
        {
            cout << item << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        if (grid.empty())
        {
            return grid;
        }

        auto totalLen = grid[0].size() * grid.size();
        k = k % totalLen;
        if (k == 0)
        {
            return grid;
        }

        for (auto i = 0; i < k; ++i)
        {
            int startPosition = i;
            int nextPosition = (i + k) % totalLen;

            int curRow = startPosition / grid[0].size();
            int curCol = startPosition % grid[0].size();
            int startValue = grid[curRow][curCol];

            bool crossFlag = false;
            while (true)
            {
                int nextRow = nextPosition / grid[0].size();
                int nextCol = nextPosition % grid[0].size();
                int nextValue = grid[nextRow][nextCol];

                grid[nextRow][nextCol] = startValue;

                startValue = nextValue;
                nextPosition = nextPosition + k;
                if (nextPosition >= totalLen)
                {
                    crossFlag = true;
                }
                nextPosition %= totalLen;
                if (crossFlag && nextPosition >= startPosition)
                {
                    break;
                }
            }
            if(nextPosition == startValue)
            {
                grid[curRow][curCol] = startValue;
            }
            printVector(grid);
        }

        return grid;
    }
};

class Solution1
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int index1 = (i * n + j + k) % (m * n);
                ret[index1 / n][index1 % n] = grid[i][j];
            }
        }
        return ret;
    }
};


int main()
{
    vector<vector<int>> grid = {{-670, -393, 34,   98,   79},
                                {693,  278,  662,  376,  -981},
                                {-271, 579,  32,   591,  638},
                                {557,  -72,  -883, -490, -666},
                                {-68,  -64,  519,  -276, 794},
                                {-737, 730,  173,  -935, 138},
                                {967,  807,  -895, 933,  135},
                                {-515, -244, -384, -194, -21},
                                {-103, 339,  165,  466,  -737},
                                {-118, -265, -445, 130,  745},
                                {359,  74,   937,  558,  -571},
                                {560,  742,  -874, -642, -759},
                                {-475, -769, 607,  668,  -779},
                                {596,  -349, -830, -951, -115},
                                {506,  502,  -827, -750, -704},
                                {-804, -877, -72,  -27,  -70},
                                {275,  560,  769,  -398, -50},
                                {824,  -470, 245,  544,  -785},
                                {-953, 473,  -173, 28,   -684},
                                {397,  -880, 194,  354,  -82},
                                {-62,  270,  -356, 743,  -483},
                                {469,  -223, 891,  954,  225},
                                {-897, 979,  -762, 303,  -929},
                                {148,  -694, -851, -504, -166},
                                {-169, 625,  11,   93,   -69},
                                {-136, 232,  684,  240,  -586},
                                {342,  473,  -83,  887,  71},
                                {-459, -302, -802, -377, 400},
                                {-81,  816,  885,  -294, 963},
                                {-84,  -760, -409, 567,  -996},
                                {331,  -173, -494, 25,   394},
                                {-57,  484,  -975, 384,  -584},
                                {360,  -684, -692, 303,  22},
                                {554,  -80,  -789, 589,  182},
                                {593,  635,  184,  172,  104},
                                {363,  806,  -371, -418, -940},
                                {388,  -799, -922, 412,  -217},
                                {-757, -854, 828,  139,  43},
                                {-479, -492, -539, -951, -675},
                                {-711, 61,   -478, 603,  461},
                                {-958, 793,  -907, 278,  -789},
                                {-133, 183,  268,  -565, -978},
                                {73,   618,  -679, 303,  -460}};

//    printVector(grid);

    Solution solution;
    solution.shiftGrid(grid, 4);

    printVector(grid);
    return 0;
}