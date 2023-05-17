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