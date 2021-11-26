//
// Created by lossv on 2021/11/26.
//


//Definition for a binary tree node.
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

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if(root == nullptr || root->val == val)
            return root;
        return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
//        auto leftNode = searchBST(root->left, val);
//        if(leftNode)
//            return leftNode;
//        auto rightNode = searchBST(root->right, val);
//        if(rightNode)
//            return rightNode;
//        return nullptr;
    }
};