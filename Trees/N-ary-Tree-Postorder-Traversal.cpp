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
            // recursion to go until leaf
            recursiveTraversal(child);
            // pushing current node after all chilren are traversed (just as in postorder)
            res.push_back(child->val);
        }
    }
    vector<int> postorder(Node *root)
    {
        if (!root)
            return res;

        recursiveTraversal(root);

        // now at last push root in the vector
        res.push_back(root->val);

        return res;
    }
};