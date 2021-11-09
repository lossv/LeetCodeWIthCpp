//
// Created by lossv on 2021/11/2.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>


struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL)
    {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};


int main()
{

    return 0;
}