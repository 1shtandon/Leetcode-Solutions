class Solution
{
public:
    long long canDistribute(long long c, vector<int> &candies)
    {
        long long kids = 0;
        for (auto &x : candies)
        {
            kids += floor(x / c);
        }
        return kids;
    }

    int maximumCandies(vector<int> &candies, long long k)
    {
        int n = candies.size();
        // if sum of candies is less than  k , then return 0;
        if (accumulate(candies.begin(), candies.end(), 0LL) < k)
        {
            return 0;
        }

        // now applying binary search on c and finding maximum c
        // minimum value can be 1
        // maximum value can be max of the array
        int low = 1, high = *max_element(candies.begin(), candies.end());
        int res = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long kids = canDistribute(mid, candies);
            if (kids >= k)
            {
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res;
    }
};