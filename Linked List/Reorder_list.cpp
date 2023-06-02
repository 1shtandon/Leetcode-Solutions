class Solution
{
public:
    void reverseList(ListNode *&node)
    {
        ListNode *prev = NULL, *curr = node, *next;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        node = prev;
    }

    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *secondHalf = slow->next;
        slow->next = NULL;
        reverseList(secondHalf);
        ListNode *firstHalf = head;
        ListNode *curr = secondHalf;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = firstHalf->next;
            firstHalf->next = curr;
            firstHalf = firstHalf->next->next;
            curr = next;
        }
    }
};