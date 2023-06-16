// gfg question sort a stack using recursion

void insertCorrectPlace(stack<int> &st, int element)
{
    // base condition to push straight away
    if (st.empty() or element >= st.top())
    {
        st.push(element);
        return;
    }

    // else remove top element and try inserting in stack
    int top = st.top();
    st.pop();

    insertCorrectPlace(st, element);
    st.push(top);
}

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack ::sort()
{
    // if the stack is empty
    if (s.empty())
        return;

    // otherwise take out top element and recursively sort rest of the stack and insert this element at correct place
    int top = s.top();
    s.pop();

    sort();

    insertCorrectPlace(s, top);
}