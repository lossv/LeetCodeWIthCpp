//
// Created by lossv on 2022/8/16.
//

#include <string>
#include <vector>

using namespace std;

class OrderedStream
{
public:
    OrderedStream(int n)
    {
        v.resize(n);
    }

    vector<string> insert(int i, string value)
    {
        vector<string> res;
        v[i - 1] = value;
        while (p < v.size() && v[p].size()) res.push_back(v[p++]);
        return res;
    }

private:
    vector<string> v;
    int p = 0;
};

int main()
{

    return 0;
}