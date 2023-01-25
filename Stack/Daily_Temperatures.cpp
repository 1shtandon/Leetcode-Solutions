/*
Approach: Stack
1. Traverse the array from right to left
2. If stack is empty, then res[i] = 0
3. If stack is not empty, then pop all elements from stack which are less than or equal to arr[i]
4. The 
*/

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and arr[st.top()] <= arr[i])
                st.pop();
            if (st.empty())
                res[i] = 0;
            else
                res[i] = st.top() - i;

            st.push(i);
        }
        return res;
    }
};