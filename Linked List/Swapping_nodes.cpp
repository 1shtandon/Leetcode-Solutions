class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *first = head;
        int ptr1 = 1;
        while (ptr1 < k)
        {
            first = first->next;
            ptr1++;
        }

        ListNode *second = head, *ptr2 = head;
        int i = 1;
        while (ptr2 and ptr2->next)
        {
            if (i >= k)
            {
                second = second->next;
            }
            ptr2 = ptr2->next;
            i++;
        }

        i = first->val;
        first->val = second->val;
        second->val = i;
        return head;
    }
};