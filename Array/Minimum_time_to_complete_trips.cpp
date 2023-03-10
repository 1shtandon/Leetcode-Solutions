/*
Approach : Binary Search

1. Using binary search, we will find the minimum time required to complete the trips.
2. Check if on mid time, we can complete the trips.
3. If we can complete the trips, then we will update the result and decrease the high value.
4. If we cannot complete the trips, then we will increase the low value.

Time Complexity: O(logn)
Space Complexity: O(1)
*/
class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        int n = time.size();
        long long res = 0;
        long long low = 0, high = totalTrips * (long long)time[0];
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long trips = 0;
            for (int i = 0; i < n; i++)
            {
                trips += mid / time[i];
            }
            if (trips >= totalTrips)
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