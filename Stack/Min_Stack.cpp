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