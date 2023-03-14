class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        if(!root)
            return 0;
        int sum = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left)
            {
                temp->left->val += temp->val * 10;
                q.push(temp->left);
            }
            if(temp->right)
            {
                temp->right->val += temp->val * 10;
                q.push(temp->right);
            }
            if(!temp->left and !temp->right)
                sum += temp->val;
        }
        return sum;
    }
};