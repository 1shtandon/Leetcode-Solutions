class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        // we can traverse the tree level wise using bfs and find sum of each level
        // thats how we can fing maximum amonng this sums

        int level = 1, maxSum = INT_MIN, res = 0;

        if (!root)
            return 0;

        // queue to store nodes
        queue<TreeNode *> q;
        q.push(root);

        // applying bfs
        while (!q.empty())
        {
            int levelSum = 0;
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode *currNode = q.front();
                q.pop();

                levelSum += currNode->val;

                if (currNode->left)
                    q.push(currNode->left);

                if (currNode->right)
                    q.push(currNode->right);
            }

            if (levelSum > maxSum)
            {
                maxSum = levelSum;
                res = level;
            }

            level++;
        }

        return res;
    }
};


// Tc : O(N)
// Sc : O(M) , where M is the maximum nodes at any level of tree