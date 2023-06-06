class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        if (!node)
            return;
        ListNode *dummy = node->next;
        node->val = dummy->val;
        node->next = dummy->next;
        return;
    }
};