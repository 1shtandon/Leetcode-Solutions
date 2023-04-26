class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        // same implementation , just fill the stack with complete array(reverse) in advance to simulate circular array
        vector<int> res(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            st.push(nums[i]);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and st.top() <= nums[i])
            {
                st.pop();
            }

            if (st.empty())
                res[i] = -1;

            else
                res[i] = st.top();

            st.push(nums[i]);
        }

        return res;
    }
};