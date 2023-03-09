/*
Approach : Fast and Slow Pointer

1. Using fast and slow pointer, we can find the cycle in the linked list.
2. If there is a cycle, then we will move the slow pointer to the head and move both the pointers by one step.
3. The point at which they meet will be the start of the cycle.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};