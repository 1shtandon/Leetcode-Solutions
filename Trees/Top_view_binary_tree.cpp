/*
Approach : Level order traversal
1. Imagine drawing vertical lines to cover the tree, root having 0 label, rightwards we do +1 and -1 for left.
2. We can store pairs in queue having node and label.
3. Now every first node of each label gives the top view, think !!
4. Every time we see a new label, insert that node's data in a map along with the label.
5. At last we have our result in the map, sorted as labels.
*/

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> res;

        if (!root)
        {
            return res;
        }

        map<int, int> mp;
        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *curr = it.first;
            int label = it.second;

            if (mp.find(label) == mp.end())
                mp[label] = curr->data;

            if (curr->left)
            {
                q.push({curr->left, label - 1});
            }
            if (curr->right)
            {
                q.push({curr->right, label + 1});
            }
        }

        for (auto it : mp)
        {
            res.push_back(it.second);
        }

        return res;
    }
};