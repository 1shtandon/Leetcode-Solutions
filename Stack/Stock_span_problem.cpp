// Stock span problem on geeks for geeks

class Solution
{
public:
    // Function to calculate the span of stock's price for all n days.
    vector<int> calculateSpan(int arr[], int n)
    {
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and arr[st.top()] <= arr[i])
                st.pop();
            if (st.empty())
                res[i] = i + 1;
            else
                res[i] = i - st.top();
            st.push(i);
        }

        return res;
    }
};