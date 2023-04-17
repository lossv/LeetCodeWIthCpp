#include "comm.h"

using namespace std;

class MajorityChecker
{
    typedef pair<int, int> PairType;
    typedef vector<vector<PairType>> ValueType;
public:
    MajorityChecker(vector<int> &arr)
    {
        record = ValueType(arr.size(), vector<PairType>(arr.size()));
        unordered_map<int, int> tmpMap;
        for (int i = 0; i < arr.size() - 1; ++i)
        {
            record[i][i] = PairType(arr[i], 1);
            tmpMap[arr[i]]++;
            for (int j = i + 1; j < arr.size(); ++j)
            {
                int curValue = arr[j];
                auto prePair = record[i][j - 1];

                tmpMap[curValue]++;

                int preCount = prePair.second;
                int curCount = tmpMap[curValue];

                if (preCount < curCount)
                {
                    record[i][j] = PairType(curValue, curCount);
                }
                else
                {
                    record[i][j] = record[i][j - 1];
                }
            }

            tmpMap.clear();

        }

    }

    int query(int left, int right, int threshold)
    {
        return record[left][right].second >= threshold ? record[left][right].first : -1;
    }

private:
    ValueType record;
};

int main()
{
    vector<int> data{1, 1, 2, 2, 1, 1};
    MajorityChecker checker(data);
    cout << checker.query(0, 5, 4);
    return 0;
}
