/*
Approach : Level order traversal, while assigning next ptr and if its the last node in level, then assign null as next
*/
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;

        queue<Node *> q;

        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                Node *nextToAssign = q.front();

                if (i + 1 < size)
                {
                    curr->next = nextToAssign;
                }
                else
                {
                    curr->next = nullptr;
                }

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
        }

        return root;
    }
};