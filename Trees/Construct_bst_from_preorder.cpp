class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &pre)
    {
        int idx = 0;
        return construct(idx, INT_MAX, pre);
    }
    TreeNode *construct(int &idx, int bound, vector<int> &pre)
    {
        if (idx == pre.size() || pre[idx] > bound)
            return NULL;
        TreeNode *root = new TreeNode(pre[idx]);
        idx++;
        root->left = construct(idx, root->val, pre);
        root->right = construct(idx, bound, pre);
        return root;
    }
};
