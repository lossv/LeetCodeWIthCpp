//
// Created by 觉而不绝 on 2023/3/15.
//

#ifndef LEETCODEWITHCPP_LCBINARYTREE_H
#define LEETCODEWITHCPP_LCBINARYTREE_H

#pragma once
// 需要的标准库
#include<vector>
#include<queue>

//使用LeetCode上树节点定义
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {}
};

//定义一个树指针类，方便释放内存
class TreeNodePtr
{
private:
    TreeNode *node;
public:
    // 默认构造函数
    TreeNodePtr() : node(nullptr)
    {}

    // 构造函数1
    TreeNodePtr(int val)
    {
        node = new TreeNode(val);
    }

    // 复制构造函数（很必要，方便临时对象的复制）
    TreeNodePtr(const TreeNodePtr &t)
    {
        if (t.node == nullptr)
        {
            node = nullptr;
            return;
        }
        node = new TreeNode(t.node->val);
    }

    // 构造函数2（为了能用nullptr进行构造而定义）
    TreeNodePtr(TreeNode *n) : node(n)
    {}

    // 析构函数，释放内存
    ~TreeNodePtr()
    {
        delete node;
    }

    // 对外接口，返回节点指针
    TreeNode *getNodePtr() const
    {
        return node;
    }
};

// 生成二叉树
TreeNode *generateTree(const std::vector<TreeNodePtr> &input)
{
    if (input.empty())
        return nullptr;

    std::queue<TreeNode *> que;
    TreeNode *node = input[0].getNodePtr();
    que.push(node);
    TreeNode *ans = node;
    int index = 0;
    int vecSize = input.size();

    while (!que.empty() && index < vecSize)
    {
        int size = que.size();
        int i = 0;
        while (i < size && index < vecSize)
        {
            node = que.front();
            que.pop();
            ++i;

            ++index;
            if (index >= vecSize)
                break;
            node->left = input[index].getNodePtr();
            if (node->left)
                que.push(node->left);

            ++index;
            if (index >= vecSize)
                break;
            node->right = input[index].getNodePtr();
            if (node->right)
                que.push(node->right);
        }
    }
    return ans;
}

//int main()
//{
//    // 2.（必要的）用一个vector来存储这些节点指针
//    std::vector<TreeNodePtr> input{5, 3, 6, 2, 4, nullptr, 8, 1, nullptr, nullptr, nullptr, 7, 9};
//    // 3. 生成树
//    TreeNode *root = generateTree(input);
///* 不能直接这样使用函数:
//TreeNode* root = generateTree({5,3,6,2,4,nullptr,8,1,nullptr,nullptr,nullptr,7,9});
//因为这里函数传入参数时，会产生临时对象，而这个临时对象只在函数范围内有效
//临时对象的消除会删除内存，从而导致指针悬挂问题
//*/
//    return 0;
//}

#endif //LEETCODEWITHCPP_LCBINARYTREE_H
