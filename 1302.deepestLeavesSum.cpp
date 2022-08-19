//
// Created by lossv on 2022/8/17.
//

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
    int deepestLeavesSum(TreeNode *root)
    {
        maxFloor = 0;
        maxSum = 0;
        CheckNext(root, 1);
        return maxSum;
    }

    void CheckNext(TreeNode *node, int curFloor)
    {
        if (!node) return;
        if (curFloor > maxFloor)
        {
            maxSum = node->val;
            maxFloor = curFloor;
        }
        else if (curFloor == maxFloor)
        {
            maxSum += node->val;
        }

        CheckNext(node->left, curFloor + 1);
        CheckNext(node->right, curFloor + 1);
    }

private:
    int maxFloor;
    int maxSum;
};
