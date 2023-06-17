class Solution
{
public:
    void insertLast(stack<int> &st, int ele)
    {
        // if empty stack, then push straight away, base case
        if (st.empty())
        {
            st.push(ele);
            return;
        }

        // we remove top element, apply recursion on smaller i/p , then push again
        int top = st.top();
        st.pop();

        insertLast(st, ele);
        st.push(top);
    }

    void solve(stack<int> &st)
    {
        // base case
        if (st.size() == 1)
        {
            return;
        }

        // applying recursion on smaller i/p
        int top = st.top();
        st.pop();

        solve(st);

        insertLast(st, top);
    }

    void Reverse(stack<int> &St)
    {

        solve(St);
    }
};