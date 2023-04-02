/*
Binary Search

Time Complexity: O(mlogm)
Space Complexity: O(1)
*/
class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        long long n = spells.size(), m = potions.size();
        vector<int> ans(n, 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++)
        {
            long long l = 0, r = m - 1;
            while (l <= r)
            {
                long long mid = (l + r) / 2;
                if ((long long)(potions[mid] * spells[i]) >= success)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            ans[i] = m - l;
        }
        return ans;
    }
};