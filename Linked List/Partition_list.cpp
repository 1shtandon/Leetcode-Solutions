class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {

        // making two lists, one for smaller values and other for greater
        // merging both of them in the end
        ListNode *smallptr = new ListNode(0);
        ListNode *greatptr = new ListNode(0);
        ListNode *smallerHead = smallptr;
        ListNode *greaterHead = greatptr;

        while (head)
        {
            // insert in smaller list
            if (head->val < x)
            {
                smallptr->next = head;
                smallptr = smallptr->next;
            }
            else
            {
                greatptr->next = head;
                greatptr = greatptr->next;
            }
            head = head->next;
        }

        // now ending list after last greater element
        greatptr->next = nullptr;

        // merging both lists
        smallptr->next = greaterHead->next;

        return smallerHead->next;
    }
};