class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums2.size();

        // storing next greater elements for whole array
        vector<int> nextGreaterElements(n);
        // storing indexes in a map
        unordered_map<int, int> indexes;
        // stack for implentation
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            // now till there is a smaller element at stack top, pop it
            while (!st.empty() and st.top() <= nums2[i])
            {
                st.pop();
            }

            // if stack becomes empty then -1
            if (st.empty())
                nextGreaterElements[i] = -1;
            else
                nextGreaterElements[i] = st.top();

            st.push(nums2[i]);

            indexes[nums2[i]] = i;
        }

        // now filling the query results in the first array itself and returning
        for (auto &x : nums1)
        {
            x = nextGreaterElements[indexes[x]];
        }

        return nums1;
    }
};