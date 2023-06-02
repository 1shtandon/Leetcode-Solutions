class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *currNode = head, *prev = NULL, *next = NULL;

        while (currNode)
        {
            // first storing next before changing reference
            next = currNode->next;
            // now connecting curr to prev instead of next
            currNode->next = prev;

            // after reversing this connection, just moving forward for same
            prev = currNode;
            currNode = next;
        }

        head = prev;

        return head;
    }
};