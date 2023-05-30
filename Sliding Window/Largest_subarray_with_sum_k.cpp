// gfg question

class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K)
    {
        int res = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        // storing the sum till that index in the map infront of the index
        for (int i = 0; i < N; i++)
        {
            sum += A[i];

            // if the remaining target is found at an index, do the calculation
            if (mp.find(sum - K) != mp.end())
            {
                res = max(res, (i - mp[sum - K]));
            }

            // if sum till an index is equal to target sum, update result
            if (sum == K)
            {
                res = max(res, i + 1);
            }

            // if not found than insert it
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }

        return res;
    }
};