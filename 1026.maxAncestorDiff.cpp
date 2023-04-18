#include "comm.h"

using namespace std;

class Solution
{
public:
    int maxAncestorDiff(TreeNode *root)
    {
        if (!root) return 0;
        dfs(root);
        return result;
    }

    std::pair<int, int> dfs(TreeNode *node)
    {
        std::vector<int> valuesMin;
        std::vector<int> valuesMax;

        if (node->left)
        {
            auto pairValue = dfs(node->left);

            result = std::max(std::abs(node->val - pairValue.first), result);
            result = std::max(std::abs(node->val - pairValue.second), result);

            valuesMin.emplace_back(pairValue.first);
            valuesMax.emplace_back(pairValue.second);

        }

        if (node->right)
        {
            auto pairValue = dfs(node->right);

            result = std::max(std::abs(node->val - pairValue.first), result);
            result = std::max(std::abs(node->val - pairValue.second), result);

            valuesMin.emplace_back(pairValue.first);
            valuesMax.emplace_back(pairValue.second);
        }

        valuesMin.emplace_back(node->val);
        valuesMax.emplace_back(node->val);

        int minValue = *std::min_element(valuesMin.begin(), valuesMin.end());
        int maxValue = *std::max_element(valuesMax.begin(), valuesMax.end());

        return {minValue, maxValue};

    }

private:
    int result;
};

int main()
{

    return 0;
}