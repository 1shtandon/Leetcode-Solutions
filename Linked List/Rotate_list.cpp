class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head or !head->next or k == 0)
            return head;

        int len = 0;

        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;

        ListNode *ptr1 = dummyNode;

        while (ptr1->next)
        {
            len++;
            ptr1 = ptr1->next;
        }

        k = k % len;
        if (k == 0)
            return head;

        ListNode *ptr2 = dummyNode;
        ptr1 = dummyNode;

        for (int i = 0; i < k; i++)
        {
            ptr2 = ptr2->next;
        }

        while (ptr2 and ptr2->next)
        {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }

        ptr2->next = dummyNode->next;
        dummyNode = ptr1->next;
        ptr1->next = NULL;

        return dummyNode;
    }
};

/*
if the questions rather asks to rotate list left like in gfg, then we can just apply same logic but for k = len - k
think!!

here's the implementation
*/

class Solution
{
public:
    // Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {

        if (!head or !head->next or k == 0)
            return head;

        int len = 0;

        Node *dummyNode = new Node(0);
        dummyNode->next = head;

        Node *ptr1 = dummyNode;

        while (ptr1->next)
        {
            len++;
            ptr1 = ptr1->next;
        }

        k = k % len;
        k = len - k;

        if (k == 0 or k == len)
            return head;

        Node *ptr2 = dummyNode;
        ptr1 = dummyNode;

        for (int i = 0; i < k; i++)
        {
            ptr2 = ptr2->next;
        }

        while (ptr2 and ptr2->next)
        {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }

        ptr2->next = dummyNode->next;
        dummyNode = ptr1->next;
        ptr1->next = NULL;

        return dummyNode;
    }
};