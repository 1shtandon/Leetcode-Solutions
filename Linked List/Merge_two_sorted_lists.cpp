class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *currNode = dummyHead;

        while (list1 and list2)
        {
            if (list1->val >= list2)
            {
                currNode->next = list2;
                list2 = list2->next;
            }
            else
            {
                currNode->next = list1;
                list1 = list1->next;
            }

            currNode = currNode->next;
        }

        // if still some list remaining , then rest of it goes now
        if (list1)
        {
            currNode->next = list1;
        }
        else if (list2)
        {
            currNode->next = list2;
        }

        return dummyHead->next;
    }
};