class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // we traverse using dfs and if we find any of the nodes, we return it, also if null is found we return null
        // for every node, if we get null from left, consider right, if we get null from right, consider left.
        // if both are not null, then we have found the lca.

        if (root == NULL)
            return NULL;

        if (root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
            return right;

        else if (right == NULL)
            return left;

        // found the lca
        else
            return root;
    }
};