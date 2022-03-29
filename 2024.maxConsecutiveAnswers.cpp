//
// Created by lossv on 2022/3/29.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution
{
public:
    int maxConsecutiveAnswers(string &answerKey, int k)
    {
        queue<int> queue1, queue2;
        int maxT = 0, kT = k, curT = 0, headIndexT = -1;
        int maxF = 0, kF = k, curF = 0, headIndexF = -1;
        for (int i = 0; i < answerKey.length(); ++i)
        {
            if (answerKey[i] == 'F')
            {
                if (kT > 0)
                {
                    kT--;
                    queue1.push(i);
                }
                else
                {
                    int tmp = queue1.front();
                    if (tmp > headIndexT)
                    {
                        headIndexT = tmp;
                    }
                    queue1.pop();
                    queue1.push(i);
                }
            }
            maxT = max(maxT, i - headIndexT);

            if (answerKey[i] == 'T')
            {
                if (kF > 0)
                {
                    kF--;
                    queue2.push(i);
                }
                else
                {
                    int tmp = queue2.front();
                    if (tmp > headIndexF)
                    {
                        headIndexF = tmp;
                    }
                    queue2.pop();
                    queue2.push(i);
                }
            }
            maxF = max(maxF, i - headIndexF);
        }

        return max(maxT, maxF);
    }
};

class Solution2
{
public:
    int maxConsecutiveChar(string &answerKey, int k, char ch)
    {
        int n = answerKey.length();
        int ans = 0;
        for (int left = 0, right = 0, sum = 0; right < n; right++)
        {
            sum += answerKey[right] != ch;
            while (sum > k)
            {
                sum -= answerKey[left++] != ch;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k)
    {
        return max(maxConsecutiveChar(answerKey, k, 'T'),
                   maxConsecutiveChar(answerKey, k, 'F'));
    }
};


int main()
{
    string answerKey = "TTFF";
    int k = 2;
    Solution solution;
    cout << solution.maxConsecutiveAnswers(answerKey, k);
    return 0;
}