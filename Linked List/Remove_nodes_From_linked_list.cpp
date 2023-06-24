/*
Approach 1 : Using stack

TC: O(n)
SC: O(n)
*/
class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        vector<ListNode *> st;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *curr = head;

        while (curr)
        {
            while (st.size() > 0 && st.back()->val < curr->val)
            {
                st.pop_back();
            }

            st.push_back(curr);
            curr = curr->next;
        }

        curr = dummy;

        for (int i = 0; i < st.size(); i++)
        {
            curr->next = st[i];
            curr = curr->next;
        }

        return dummy->next;
    }
};

/*
Approach 2 : Using recursion

TC: O(n)

*/
class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        head->next = removeNodes(head->next);

        if (head->val < head->next->val)
        {
            return head->next;
        }

        return head;
    }
};