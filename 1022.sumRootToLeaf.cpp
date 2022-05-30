//
// Created by lossv on 2022/5/30.
//

#include <string>
#include <bitset>
#include <iostream>

using namespace std;

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
    Solution()
    {
        result = 0;
    }

    int sumRootToLeaf(TreeNode *root, string tmpStr = "")
    {
        if (root->left == NULL && root->right == NULL)
        {
            tmpStr += (char) root->val;
            return convert(tmpStr);
        }
        if (root->left != NULL)
        {
            result += sumRootToLeaf(root->left, tmpStr + (char) root->val);
        }
        if (root->right != NULL)
        {
            result += sumRootToLeaf(root->right, tmpStr + (char) root->val);
        }

        return result;
    }

    int convert(string &source)
    {

        if (source.empty())
        {
            return 0;
        }
        bitset<10> bit(source);

        return bit.to_ulong();
    }

private:
    int result;
};

int convert(string &source)
{

    if (source.empty())
    {
        return 0;
    }
    bitset<10> bit(source);

    return bit.to_ulong();
}


class Solution2 {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        auto dfs = [&](auto && dfs, TreeNode* root, int x)
        {
            if (root == nullptr) return ;
            if (root->left == nullptr and root->right == nullptr)
                sum += x<<1 | root->val;
            dfs(dfs, root->left, x<<1 | root->val);
            dfs(dfs, root->right, x<<1 | root->val);
            return ;
        };
        dfs(dfs, root, 0);
        return sum;
    }
};

int main()
{
    string a = "";
    cout << convert(a) << endl;

    return 0;
}