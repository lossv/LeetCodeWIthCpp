#include "comm.h"

using namespace std;


class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        map<int, int> mapID;
        set<int> setID;
        int startTime = 0;
        int result = INT32_MAX;
        int iTmpTime = 0;

        for (auto &item: logs)
        {
            int useTime = item[1] - startTime;
            startTime = item[1];
            if(useTime > iTmpTime)
            {
                iTmpTime = useTime;
                result = item[0];
            }
            else if(useTime == iTmpTime)
            {
                result = min(result, item[0]);
            }
        }


        return result;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> logs{{1,1},{3,7},{2,12},{7,17}};

    int n = 10;

    cout << solution.hardestWorker(n, logs);

    return 0;
}