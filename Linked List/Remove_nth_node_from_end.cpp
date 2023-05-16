class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *ptr1 = dummyHead, *ptr2 = dummyHead;
        int i = 0;
        while (i < n)
        {
            ptr2 = ptr2->next;
            i++;
        }
        while (ptr2 and ptr2->next)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr1->next = ptr1->next->next;
        return dummyHead->next;
    }
};