class Solution
{
private:
    TreeNode *helper(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp)
    {
        // break condition
        if (preStart > preEnd or inStart > inEnd)
            return NULL;

        // filling map
        for (int i = inStart; i <= inEnd; i++)
            mp[inorder[i]] = i;

        // creating root node as first element of preorder
        TreeNode *root = new TreeNode(preorder[preStart]);

        // finding index of root in inorder
        int rootIndex = mp[root->val];
        int leftSubtreeSize = rootIndex - inStart;

        // left subtree
        root->left = helper(preorder, preStart + 1, preStart + leftSubtreeSize, inorder, inStart, rootIndex - 1, mp);
        // right subtree
        root->right = helper(preorder, preStart + leftSubtreeSize + 1, preEnd, inorder, rootIndex + 1, inEnd, mp);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mp;
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    }
};