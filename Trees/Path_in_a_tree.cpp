/*
Approach : Inorder traversal
1. Every time we visit a node, insert it in the vector.
2. Check if the value of the node is equal to x.
3. If yes, return true.
4. Now, if not equal to x, apply recursion on left and right both, and if any of
them return true, consider true.
5. If not, then we backtrack and remove the node from the vector, and send
false.

Time Complexity: O(n)
Space Complexity: O(n)
*/

bool solve(TreeNode<int> *root, vector<int> &res, int x)
{
    if (!root)
        return false;

    res.push_back(root->data);

    if (root->data == x)
        return true;

    if (solve(root->left, res, x) or solve(root->right, res, x))
        return true;

    res.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> res;

    if (!root)
        return res;

    solve(root, res, x);
    return res;
}