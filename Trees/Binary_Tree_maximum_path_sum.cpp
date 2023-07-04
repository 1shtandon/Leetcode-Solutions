/*
Approach similar to finding the diameter of tree.
Considering every node in the path and finding answer for it, by finding path for the left and right
*/

class Solution
{
public:
    int res = INT_MIN;

    int solve(TreeNode *node)
    {
        if (!node)
            return 0;

        int left = max(0, solve(node->left));
        int right = max(0, solve(node->right));

        res = max(res, left + right + node->val);

        return max({left, right}) + node->val;
    }

    int maxPathSum(TreeNode *root)
    {
        solve(root);
        return res;
    }
};