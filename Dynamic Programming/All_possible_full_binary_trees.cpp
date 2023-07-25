class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        vector<TreeNode *> ans;
        if (n == 1)
        {
            TreeNode *root = new TreeNode(0);
            ans.push_back(root);
            return ans;
        }
        for (int i = 0; i < n; i++)
        {
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(n - i - 1);
            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
};