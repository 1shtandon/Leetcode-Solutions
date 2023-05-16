class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // if less than two nodes
        if (!head or !head->next)
            return head;

        ListNode *tempNode = new ListNode(0);

        ListNode *prevNode = tempNode, *currNode = head;
        prevNode->next = head;

        while (currNode and currNode->next)
        {
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;

            prevNode = currNode;
            currNode = currNode->next;
        }
        return tempNode->next;
    }
};