class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        if (!root)
            return res;

        queue<TreeNode *> q;

        q.push(root);

        // applying level order using bfs
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }

            res.push_back(level);
        }

        // reversing alternatively to create zig-zag pattern

        for (int i = 1; i < res.size(); i += 2)
        {
            reverse(res[i].begin(), res[i].end());
        }

        return res;
    }
};

