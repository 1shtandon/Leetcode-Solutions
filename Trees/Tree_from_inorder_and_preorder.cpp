/*
Approach: Recursion

1. The first element of preorder is the root node.
2. Finding the index of root in inorder, we can find the size of left subtree.
3. Now, we can recursively call the function for left and right subtree.
4. The left subtree will have the elements from preStart+1 to preStart+leftSubtreeSize.
5. The right subtree will have the elements from preStart+leftSubtreeSize+1 to preEnd.
6. The left subtree will have the elements from inStart to rootIndex-1.
7. The right subtree will have the elements from rootIndex+1 to inEnd.
8. We will also pass a map, which will store the index of every element in inorder.

Time Complexity: O(n)
Space Complexity: O(n)
*/
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