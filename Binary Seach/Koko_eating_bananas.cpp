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
    long long timeTaken(vector<int> &piles, int speed)
    {

        long long time = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            time += ceil((long double)piles[i] / speed);
        }
        return time;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        // the minimum eating speed is 1
        // the maximum eating speed is the maximum number of bananas in a pile
        // now apply binary search on the answer to find if with this speed, piles can be finished or
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int res = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long time = timeTaken(piles, mid);
            if (time <= h)
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