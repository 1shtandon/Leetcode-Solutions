class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // approach : making both pointers at same distance from intersection point
        // traverse both linked lists with 2 pointers
        // when one pointer reaches end of linked list, make it point to head of other linked list
        // when both pointers are at same distance from intersection point, they will meet at intersection point
        ListNode *ptr1 = headA, *ptr2 = headB;

        while (ptr1 != ptr2)
        {
            if (ptr1)
                ptr1 = ptr1->next;
            else
                ptr1 = headB;

            if (ptr2)
                ptr2 = ptr2->next;
            else
                ptr2 = headA;
        }

        return ptr1;
    }
};