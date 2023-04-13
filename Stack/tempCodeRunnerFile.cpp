
// Linked List
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    int n = pushed.size();
    int ptr1 = 0, ptr2 = 0;
    stack<int> st;
    while (ptr1 < n)
    {
        if (pushed[ptr1] == popped[ptr2])
        {
            ptr1++;
            ptr2++;
        }
        else if (!st.empty() and st.top() == popped[ptr2])
        {
            st.pop();
            ptr2++;
        }
        else
        {
            st.push(pushed[ptr1]);
            ptr1++;
        }
    }
    while (!st.empty() and st.top() == popped[ptr2])
    {
        st.pop();
        ptr2++;
    }
    return st.empty();
}