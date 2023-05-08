//  Same as nearest smaller to right

class Solution
{
public:

    vector<int> finalPrices(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> discount(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and st.top() > prices[i])
            {
                st.pop();
            }

            if (st.empty())
                discount[i] = 0;
            else
                discount[i] = st.top();

            st.push(prices[i]);
        }

        for(int i = 0; i < n; i++)
        {
            prices[i] -= discount[i];
        }

        return prices;
    }
};