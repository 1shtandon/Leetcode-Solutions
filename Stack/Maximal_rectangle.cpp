class Solution
{
public:

    // finding nearest smaller indexes to left of array 
    vector<int> nearestSmallertoLeftIndexes(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                res[i] = -1;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    // finding nearest smaller indexes to right of array
    vector<int> nearestSmallertoRightIndexes(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                res[i] = n;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    // after finding left and right limit, this method finds maximum area among the array given
    int maxAreaofHistogram(vector<int> arr)
    {
        vector<int> rightLimit = nearestSmallertoRightIndexes(arr);
        vector<int> leftLimit = nearestSmallertoLeftIndexes(arr);
        int res = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            res = max(res, arr[i] * (rightLimit[i] - leftLimit[i] - 1));
        }
        return res;
    }

    // we are converting 2d to 1d here
    // Consider gradually for every row, we have different kinds of array for histogram
    // among these, we are finding the maximum of all
    // starting from first row, if there is 0 then that whole height of bar becomes 0 (no ground), for a 1 it increments
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> histogramArray(cols);
        for (int k = 0; k < cols; k++)
        {
            if (matrix[0][k] == '0')
                histogramArray[k] = 0;
            else
                histogramArray[k] = 1;
        }
        int maxArea = maxAreaofHistogram(histogramArray);
        for (int i = 1; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == '0')
                    histogramArray[j] = 0;
                else
                    histogramArray[j]++;
            }
            maxArea = max(maxArea, maxAreaofHistogram(histogramArray));
        }
        return maxArea;
    }
};