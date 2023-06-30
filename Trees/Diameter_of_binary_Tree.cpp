/*
Approach: DFS
1. We will do a DFS traversal of the tree.
2. For every node, if we consider it as the curving point, then we will find the maximum path from that node to be : left_height + right_height.
3. We will do this for every node, and keep track of the maximum path.
4. Just writing the code to find the max height of tree from given node, and updating the max path in that itself.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution
{
public:
    int res = 0;

    int solve(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        res = max(res, left + right);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        solve(root);
        return res;
    }
};