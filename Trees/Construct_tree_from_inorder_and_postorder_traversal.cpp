// Approach: Recursion

// 1. The last element of postorder is the root node.
// 2. Finding the index of root in inorder, we can find the size of left subtree.
// 3. Now, we can recursively call the function for left and right subtree.
// 4. The left subtree will have the elements from postStart to postStart+leftSubtreeSize-1.
// 5. The right subtree will have the elements from postStart+leftSubtreeSize to postEnd-1.
// 6. The left subtree will have the elements from inStart to rootIndex-1.
// 7. The right subtree will have the elements from rootIndex+1 to inEnd.
// 8. We will also pass a map, which will store the index of every element in inorder.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
private:
    TreeNode *helper(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp)
    {
        // break condition
        if (postStart > postEnd or inStart > inEnd)
            return NULL;

        // creating root node as last element of postorder
        TreeNode *root = new TreeNode(postorder[postEnd]);

        // finding index of root in inorder
        int rootIndex = mp[root->val];
        int leftSubtreeSize = rootIndex - inStart;

        // left subtree
        root->left = helper(postorder, postStart, postStart + leftSubtreeSize - 1, inorder, inStart, rootIndex - 1, mp);
        // right subtree
        root->right = helper(postorder, postStart + leftSubtreeSize, postEnd - 1, inorder, rootIndex + 1, inEnd, mp);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return helper(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    }
};