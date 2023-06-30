void solve(Node *node, vector<int> &res, int level)
{
    if (!node)
        return;

    // if for a level, its element is not in the vector, insert it
    if (res.size() == level)
    {
        res.push_back(node->data);
    }

    solve(node->left, res, level + 1);
    solve(node->right, res, level + 1);

    return;
}

vector<int> leftView(Node *root)
{
    vector<int> res;
    int level = 0;

    solve(root, res, level);

    return res;
}