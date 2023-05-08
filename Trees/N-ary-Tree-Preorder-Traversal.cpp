/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> res;

    void recursiveTraversal(Node *node)
    {
        // base condition
        if (!node)
            return;

        // now traverse in children until leaf node
        for (auto &child : node->children)
        {
            // pushing current node before all chilren are traversed (just as in preorder)
            res.push_back(child->val);
            // recursion to go until leaf
            recursiveTraversal(child);
        }
    }
    vector<int> preorder(Node *root)
    {
        if (!root)
            return res;

        // first push root in the vector
        res.push_back(root->val);
        recursiveTraversal(root);
        return res;
    }
};