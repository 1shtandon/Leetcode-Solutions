/*
Approach : Two Pointers

Time Complexity : O(n)
Space Complexity : O(1)
*/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxArea = -1;
        int start = 0, end = height.size() - 1;
        while (end > start)
        {
            if (height[start] > height[end])
            {
                maxArea = max(maxArea, height[end] * (end - start));
                end--;
            }
            else
            {
                maxArea = max(maxArea, height[start] * (end - start));
                start++;
            }
        }
        return maxArea;
    }
};