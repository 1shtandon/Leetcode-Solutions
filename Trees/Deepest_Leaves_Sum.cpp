class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        if (!root)
            return 0;

        // performing level order traversal and summing nodes at each level. return the last level sum
        int levelSum = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            // intiating level sum at each level
            levelSum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *currNode = q.front();
                q.pop();

                levelSum += currNode->val;

                if (currNode->left != NULL)
                {
                    q.push(currNode->left);
                }
                if (currNode->right != NULL)
                {
                    q.push(currNode->right);
                }
            }
        }
        return levelSum;
    }
};