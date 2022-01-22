//
// Created by 觉而不绝 on 2022/1/22.
//

#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

//class Solution
//{
//public:
//    int minJumps(vector<int> &arr)
//    {
//        int minStep = 0;
//
//        if (arr.empty() || arr.size() == 1)
//            return minStep;
//
//        if (arr[0] == arr[arr.size() - 1])
//            return 1;
//
//        // 记录当前value的 minStep
//        map<int, int> mapTmp;
//        // 记录第一次出现的index
//        map<int, int> mapFirst;
//
//        map<int, int> mapSecond;
//
//        mapTmp[arr[0]] = 0;
//
//        mapFirst[arr[0]] = 0;
//
//        mapSecond[arr[0]] = 1;
//
//        for (int i = 0; i < arr.size(); ++i)
//            if (mapFirst.find(arr[i]) == mapFirst.end())
//                mapFirst[arr[i]] = i;
//
//        // 要记录第二次遇到的步数
//        for (int i = 1; i < arr.size(); ++i)
//        {
//            int value = arr[i];
//
//            if (mapTmp.find(value) == mapTmp.end())
//            {
//                mapTmp[value] = ++minStep;
//                mapSecond[value]++;
//            }
//            else
//            {
//                int preIndex = mapFirst[value];
//                if(mapSecond[value] > 1)
//                {
//                    minStep = min({mapTmp[value], minStep + 1, mapTmp[arr[preIndex + 1]] + 2});
//                }
//                else
//                {
//                    int preValue = mapTmp[value];
//                    mapSecond[value]++;
//                    minStep = min({mapTmp[value] + 1, minStep + 1, mapTmp[arr[preIndex + 1]] + 2});
//                    if(minStep < preValue)
//                        mapSecond[value]--;
//                }
//
//                mapTmp[value] = minStep;
//            }
//        }
//
//        return minStep;
//    }
//};

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> idxSameValue;
        for (int i = 0; i < arr.size(); i++) {
            idxSameValue[arr[i]].push_back(i);
        }
        unordered_set<int> visitedIndex;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        visitedIndex.emplace(0);
        while (!q.empty()) {
            auto [idx, step] = q.front();
            q.pop();
            if (idx == arr.size() - 1) {
                return step;
            }
            int v = arr[idx];
            step++;
            if (idxSameValue.count(v)) {
                for (auto & i : idxSameValue[v]) {
                    if (!visitedIndex.count(i)) {
                        visitedIndex.emplace(i);
                        q.emplace(i, step);
                    }
                }
                idxSameValue.erase(v);
            }
            if (idx + 1 < arr.size() && !visitedIndex.count(idx + 1)) {
                visitedIndex.emplace(idx + 1);
                q.emplace(idx + 1, step);
            }
            if (idx - 1 >= 0 && !visitedIndex.count(idx - 1)) {
                visitedIndex.emplace(idx - 1);
                q.emplace(idx - 1, step);
            }
        }
        return -1;
    }
};


int main()
{
    Solution solution;
//    vector<int> arr = {25, -28, -51, 61, -74, -51, -30, 58, 36, 68, -80, -64, 25, -30, -53, 36, -74, 61, -100, -30, -52};
//    vector<int> arr = {7,7,2,1,7,7,7,3,4,1};
    vector<int> arr = {80, -86, 40, 12, 40, -98, 12, -86, -79, -4, -79, 71, 44, -43, -9, -88, 88, -43, 31, 4, 71, -86,55, -9, -65};     // 5
//    vector<int> arr = {1, 1, 1, 1, 1, 1, 1, 1, 1, 2};
//    vector<int> arr = {25,-28,-51,61,-74,-51,-30,58,36,68,-80,-64,25,-30,-53,36,-74,61,-100,-30,-52};

    cout << solution.minJumps(arr) << endl;
    return 0;
}