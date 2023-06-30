class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});

        long long res = 0;

        while (!q.empty())
        {
            int size = q.size();
            long long start, end;
            long long min = q.front().second;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front().first;
                long long level = q.front().second - min;
                q.pop();

                if (i == 0)
                    start = level;
                if (i == size - 1)
                    end = level;

                if (node->left)
                    q.push({node->left, 2 * level + 1});
                if (node->right)
                    q.push({node->right, 2 * level + 2});
            }

            res = max(res, end - start + 1);
        }

        return res;
    }
};