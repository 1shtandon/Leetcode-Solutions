class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *currentNode = dummyHead;

        while (list1 and list2)
        {
            if (list1->val > list2->val)
            {
                currentNode->next = list2;
                list2 = list2->next;
            }
            else
            {
                currentNode->next = list1;
                list1 = list1->next;
            }
            currentNode = currentNode->next;
        }

        if(list1)
        {
            currentNode->next = list1;
        }
        else
            currentNode->next = list2;

        return dummyHead->next;
    }
};