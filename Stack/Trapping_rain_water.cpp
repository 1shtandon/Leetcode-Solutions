class Solution
{
public:
    vector<pair<int, int>> findWaterHeight(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left_max(n, -1);
        vector<int> right_max(n, -1);
        stack<int> st;

        // Finding maximum element in right subarray for each element
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[i] >= arr[st.top()])
            {
                st.pop();
            }
            if (!st.empty())
            {
                right_max[i] = arr[st.top()];
            }
            // only push in stack if it gets empty (current element is maximum)
            if (st.empty())
                st.push(i);
        }

        // Clearing stack to use it again for finding maximum element in left subarray
        st.pop();

        // Finding maximum element in left subarray for each element
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] >= arr[st.top()])
            {
                st.pop();
            }
            if (!st.empty())
            {
                left_max[i] = arr[st.top()];
            }
            // only push in stack if it gets empty (current element is maximum)
            if (st.empty())
                st.push(i);
        }

        // Combining left and right max arrays for each element to get the final result
        vector<pair<int, int>> result(n);
        for (int i = 0; i < n; i++)
        {
            result[i] = make_pair(left_max[i], right_max[i]);
        }

        return result;
    }

    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<pair<int, int>> limits = findWaterHeight(height);
        int total = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int x = limits[i].first, y = limits[i].second;
            if (x != -1 and y != -1)
            {
                total += min(x, y) - height[i];
            }
        }
        return total;
    }
};