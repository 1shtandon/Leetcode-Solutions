class Solution
{
public:
    TreeNode *helper(TreeNode *node, int val)
    {
        if (!node)
        {
            return nullptr;
        }

        if (node->val == val)
        {
            return node;
        }

        if (val > node->val)
        {
            return helper(node->right, val);
        }
        else
        {
            return helper(node->left, val);
        }
    }

    TreeNode *searchBST(TreeNode *root, int val)
    {
        return helper(root, val);
    }
};