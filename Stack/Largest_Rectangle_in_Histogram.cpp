/*
Approach: Using Stack
1. Find the nearest smaller element to the right and the nearest smaller element to the left for each element in the array.
2. Calculate the area of the rectangle formed by the current element and the nearest smaller element to the right and the nearest smaller element to the left.
3. Return the maximum area.
*/

class Solution
{
public:
    int largestRectangleArea(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> smallerRight(n), smallerLeft(n);
        stack<int> st1, st2;
        int res = -1;
        // storing nearest smaller to right indexes for each element
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st1.empty() and arr[st1.top()] >= arr[i])
                st1.pop();
            if (st1.empty())
                smallerRight[i] = n;
            else
                smallerRight[i] = st1.top();
            st1.push(i);
        }

        // storing nearest smaller to left indexes for each element from 1 to n - 1
        for (int j = 0; j < n; j++)
        {
            while (!st2.empty() and arr[st2.top()] > arr[j])
                st2.pop();
            if (st2.empty())
                smallerLeft[j] = -1;
            else
                smallerLeft[j] = st2.top();
            st2.push(j);
        }
        for (int i = 0; i < n; i++)
        {
            res = max(res, arr[i] * (smallerRight[i] - smallerLeft[i] - 1));
        }
        return res;
    }
};