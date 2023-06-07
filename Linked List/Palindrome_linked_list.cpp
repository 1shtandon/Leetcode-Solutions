class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> st;

        if (!head or !head->next)
            return true;

        ListNode *dummyHead = head;

        while (dummyHead)
        {
            st.push(dummyHead->val);
            dummyHead = dummyHead->next;
        }

        while (st.size() / 2)
        {
            if (st.top() != head->val)
            {
                return false;
            }

            st.pop();
            head = head->next;
        }

        return true;
    }
};