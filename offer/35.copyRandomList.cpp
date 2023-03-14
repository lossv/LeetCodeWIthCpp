//
// Created by 觉而不绝 on 2023/3/13.
//

#include "comm.h"

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (cachedNode.find(head) == cachedNode.end())
        {
            auto newNode = new Node(head->val);
            cachedNode[head] = newNode;
            newNode->next = copyRandomList(head->next);
            newNode->random = copyRandomList(head->random);
        }

        return cachedNode[head];
    }


    Node *copyRandomList2(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (!cachedNode.count(head))
        {
            Node *headNew = new Node(head->val);
            cachedNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }


private:
    unordered_map<Node *, Node *> cachedNode;
};

Node *MakeList(vector<vector<int> > &list)
{
    Node *pResultNode = NULL;
    Node *tmpNewHead = NULL;
    vector<Node *> listNode;
    for (auto &item: list)
    {
        auto key = item[0];
        auto value = item[1];

        auto pTmpNode = new Node(key);
        if (pResultNode == NULL)
        {
            pResultNode = pTmpNode;
            tmpNewHead = pTmpNode;
        }
        else
        {
            tmpNewHead->next = pTmpNode;
        }

        tmpNewHead = pTmpNode;

        listNode.push_back(pTmpNode);

    }

    int index = 0;
    for (auto pNode = pResultNode; pNode; pNode = pNode->next)
    {
        auto randomNodeIndex = list[index++][1];
        if (randomNodeIndex != -1)
        {
            auto randomNode = listNode[randomNodeIndex];
            pNode->random = randomNode;
        }

    }

    return pResultNode;

}

void Show(Node *head)
{
    for (auto node = head; node; node = node->next)
    {
        std::printf("cur_value=%d random_value=%d \n", node->val, node->random ? node->random->val : -1);
    }
}

int main()
{
    Solution solution;
    vector<vector<int> > listValue;
    listValue.push_back({7, -1});
    listValue.push_back({13, 0});
    listValue.push_back({11, 4});
    listValue.push_back({10, 2});
    listValue.push_back({1, 0});
    auto list = MakeList(listValue);
    Show(list);

    auto res = solution.copyRandomList(list);

    ::printf("\n");
    Show(res);

    std::printf("done");
}