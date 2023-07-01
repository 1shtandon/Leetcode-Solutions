class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // if both roots are null then true
        if (p == NULL and q == NULL)
            return true;
        // if value not same or any one is null then false
        if ((p == NULL or q == NULL) or (p->val != q->val))
            return false;

        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};