class Solution
{
public:
    bool validateNodes(TreeNode *root, TreeNode *rangeL, TreeNode *rangeR)
    {
        if (!root)
            return true;

        if ((rangeL != NULL and root->val <= rangeL->val) or (rangeR != NULL and root->val >= rangeR->val))
            return false;
        else
            return validateNodes(root->left, rangeL, root) and validateNodes(root->right, root, rangeR);
    }

    bool isValidBST(TreeNode *root)
    {
        return validateNodes(root, NULL, NULL);
    }
};