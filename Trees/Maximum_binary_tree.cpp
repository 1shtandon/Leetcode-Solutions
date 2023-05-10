class Solution
{
public:
    int maxIdx(vector<int> &nums, int &start, int &end)
    {
        int res = -1;
        int idx = -1;
        for (int i = start; i < end + 1; i++)
        {
            if (nums[i] > res)
            {
                res = nums[i];
                idx = i;
            }
        }
        return idx;
    }

    TreeNode *constructTree(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return NULL;
        if (start == end)
            return new TreeNode(nums[start]);

        int index = maxIdx(nums, start, end);

        TreeNode *root = new TreeNode(nums[index]);

        root->left = constructTree(nums, start, index - 1);
        root->right = constructTree(nums, index + 1, end);
        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        int n = nums.size();
        TreeNode *root = constructTree(nums, 0, n - 1);
        return root;
    }
};