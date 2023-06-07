class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head or k == 1)
            return head;

        int len = 0;
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;

        ListNode *curr = dummyNode, *prev = dummyNode, *next = dummyNode;

        while (curr->next)
        {
            len++;
            curr = curr->next;
        }

        // for considering only k group wise
        while (len >= k)
        {
            curr = prev->next;
            next = curr->next;

            // now reversing each link at a time for k - 1 iters
            for (int i = 1; i < k; i++)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }

            prev = curr;

            len -= k;
        }

        return dummyNode->next;
    }
};