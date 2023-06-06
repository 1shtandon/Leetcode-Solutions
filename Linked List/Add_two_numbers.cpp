class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyNode = new ListNode(0);
        ListNode *curr = dummyNode;

        int carry = 0;

        while (l1 or l2)
        {
            int sum = 0;

            if (l1)
                sum += l1->val;
            if (l2)
                sum += l2->val;

            sum += carry;
            carry = sum / 10;

            curr->next = new ListNode(sum % 10);

            curr = curr->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (carry)
        {
            curr->next = new ListNode(carry);
        }

        return dummyNode->next;
    }
};