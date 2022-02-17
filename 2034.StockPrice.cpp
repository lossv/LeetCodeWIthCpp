//
// Created by 觉而不绝 on 2022/1/23.
//
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

typedef pair<int, int> pii;

class StockPrice
{
    map<int, int> mp;
    multiset<int> s;
public:
    StockPrice()
    {

    }

    void update(int timestamp, int price)
    {
        auto it = mp.find(timestamp);
        if (it != mp.end())
        {
            s.erase(s.find(it->second));
            it->second = price;
        } else
        {
            mp.emplace(timestamp, price);
        }
        s.emplace(price);
    }

    int current()
    {
        return mp.rbegin()->second;
    }

    int maximum()
    {
        return *s.rbegin();
    }

    int minimum()
    {
        return *s.begin();
    }
};


int main()
{
    return 0;
}
