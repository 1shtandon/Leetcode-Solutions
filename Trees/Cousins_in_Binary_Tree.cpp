class Solution
{
private:
    int findLevel(TreeNode *root, int node, int level)
    {
        if (!root)
            return 0;
        if (root->val == node)
            return level;

        int leftSearch = findLevel(root->left, node, level + 1);
        if (leftSearch != 0)
            return leftSearch;

        return findLevel(root->right, node, level + 1);
    }

    bool checkSameParents(TreeNode *root, int x, int y)
    {
        if (!root)
            return false;

        if (root->left and root->right)
        {
            if (root->left->val == x and root->right->val == y)
                return true;
            if (root->left->val == y and root->right->val == x)
                return true;
        }

        return checkSameParents(root->left, x, y) or checkSameParents(root->right, x, y);
    }

public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (!root)
            return false;

        int xLevel = findLevel(root, x, 1);
        int yLevel = findLevel(root, y, 1);

        if (xLevel != yLevel)
            return false;

        return !checkSameParents(root, x, y);
    }
};