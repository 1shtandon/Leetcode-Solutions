/*
Approach : Level order traversal
1. Approach same as that of top/bottom view of tree where we have a queue and map to make vertical lines on the tree using labels.
2. Here we also store horizontal level along with the vertical label line
*/
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> res;

        if (!root)
            return res;

        queue<pair<TreeNode *, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;

        // queue stores node, vertical label, horizontal level
        // map stores label, map of level and multiset of nodes
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            TreeNode *node = p.first;
            int label = p.second.first;
            int level = p.second.second;

            mp[label][level].insert(node->val);

            if (node->left)
                q.push({node->left, {label - 1, level + 1}});
            if (node->right)
                q.push({node->right, {label + 1, level + 1}});
        }

        for (auto p : mp)
        {
            vector<int> temp;
            for (auto q : p.second)
            {
                for (auto r : q.second)
                {
                    temp.push_back(r);
                }
            }
            res.push_back(temp);
        }

        return res;
    }
};

// TC: O(nlogn)
// SC: O(n)