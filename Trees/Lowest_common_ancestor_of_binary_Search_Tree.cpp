class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root;

        int currNode = root->val;

        if (currNode > p->val && currNode > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (currNode < p->val && currNode < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};