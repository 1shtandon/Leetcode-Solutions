class Solution
{
public:
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *currNode = head, *next = NULL, *prev = NULL;

        while (currNode)
        {
            next = currNode->next;
            currNode->next = prev;
            prev = currNode;
            currNode = next;
        }

        head = prev;

        return head;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // reversing both linked lists
        l1 = reverseLinkedList(l1);
        l2 = reverseLinkedList(l2);

        ListNode *dummyNode = new ListNode(0);
        ListNode *currNode = dummyNode;
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

            currNode->next = new ListNode(sum % 10);

            currNode = currNode->next;

            if (l1)
                l1 = l1->next;

            if (l2)
                l2 = l2->next;
        }

        if (carry)
            currNode->next = new ListNode(carry);

        return dummyNode->next;
    }
};

// Time Complexity: O(N) + O(N) + O(N) = O(N)
// Space Complexity: O(N) = O(N)

// Stack Solution

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;
        ListNode *curr = l1;
        while (curr)
        {
            s1.push(curr->val);
            curr = curr->next;
        }
        curr = l2;
        while (curr)
        {
            s2.push(curr->val);
            curr = curr->next;
        }
        int carry = 0;

        ListNode *head = NULL;

        while (!s1.empty() or !s2.empty() or carry)
        {
            int sum = 0;

            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }

            sum += carry;

            carry = sum / 10;

            ListNode *newNode = new ListNode(sum % 10);

            newNode->next = head;

            head = newNode;
        }

        return head;
    }
};