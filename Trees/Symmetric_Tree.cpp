class Solution
{
public:
    bool mirror(TreeNode *node1, TreeNode *node2)
    {
        if (!node1 and !node2)
            return true;

        if (!node1 or !node2)
            return false;

        if (node1 and node2)
        {
            if (node1->val != node2->val)
                return false;
            else
                return mirror(node1->left, node2->right) and mirror(node1->right, node2->left);
        }
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return mirror(root->left, root->right);
    }
};