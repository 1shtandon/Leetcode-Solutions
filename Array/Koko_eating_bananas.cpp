/*
Approach : Binary Search

1. Using binary search, we will find the minimum speed at which Koko can eat all the bananas.
2. Check if on mid speed, Koko can eat all the bananas.
3. If Koko can eat all the bananas, then we will update the result and decrease the high value.
4. If Koko cannot eat all the bananas, then we will increase the low value.

Time Complexity: O(logn)
Space Complexity: O(1)
*/

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        long long low = 1, high = 1e9;
        long long res = 0;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long hours = 0;
            for (int i = 0; i < n; i++)
            {
                hours += (long long)(piles[i] + mid - 1) / mid;
            }
            if (hours <= h)
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};