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
        int res = 0;
        int n = height.size();
        int start = 0, end = n - 1;

        while (start < end)
        {
            int amountOfWater = (end - start) * (min(height[end], height[start]));
            res = max(res, amountOfWater);

            if (height[start] < height[end])
            {
                start++;
            }

            else
            {
                end--;
            }
        }

        return res;
    }
};