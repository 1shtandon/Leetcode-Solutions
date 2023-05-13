/*
Approach : Vector of pairs
1. We will store the value and the minimum value till that point in the vector of pairs.
2. Push the value and the minimum value till that point in the vector of pairs.
3. Pop the last element of the vector of pairs.
4. Return the top element of the vector of pairs.

Time Complexity : O(1)
Space Complexity : O(n)

*/

class MinStack
{
public:
    vector<pair<int, int>> st;

    MinStack()
    {
    }

    void push(int val)
    {
        if (st.size() == 0)
            st.push_back({val, val});

        else
            st.push_back({val, min(val, st.back().second)});
    }

    void pop()
    {
        if (st.size() == 0)
            return;

        else
            st.pop_back();
    }

    int top()
    {
        return st.back().first;
    }

    int getMin()
    {
        return st.back().second;
    }
};

/*
Approach 2 : Two Stacks
1. We take two stacks, one for storing the elements and the other for storing the minimum element till that point.
2. If the element to be pushed is less than or equal to the top element of the minimum stack, then we will push the element in the minimum stack.
3. On popping, if the element to be popped is equal to the top element of the minimum stack, then we will pop the top element of the minimum stack.

Time Complexity : O(1)
Space Complexity : O(n)


*/

class MinStack
{
public:
    stack<int> st1, st2;
    MinStack()
    {
    }

    void push(int val)
    {
        st1.push(val);
        if (st2.empty() or val <= st2.top())
        {
            st2.push(val);
        }
    }

    void pop()
    {
        if (st1.top() == st2.top())
        {
            st2.pop();
            st1.pop();
        }
        else
            st1.pop();
    }

    int top()
    {
        return st1.top();
    }

    int getMin()
    {
        return st2.top();
    }
};
