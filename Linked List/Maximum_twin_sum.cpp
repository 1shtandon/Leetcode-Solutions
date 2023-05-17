class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *ptr1 = head, *ptr2 = head;
        int n = 0;
        while (ptr2 and ptr2->next)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            n++;
        }
        // now reversing the second half of the linked list
        ListNode *prev = NULL, *curr = ptr1, *next = NULL;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        int max_sum = 0;
        ptr1 = head;
        ptr2 = prev;
        while (n--)
        {
            max_sum = max(max_sum, ptr1->val + ptr2->val);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return max_sum;

    }
};