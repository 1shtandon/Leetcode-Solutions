// Recursive and Memoized Solution

class Solution
{
public:
    bool recursion(int idx, vector<int> &nums, int &n, vector<int> &dp)
    {
        if (idx == n)
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        // case 1 : 2 equal elements
        if (idx + 1 < n and nums[idx] == nums[idx + 1])
        {
            // check for valid partition in the rest of array
            if (recursion(idx + 2, nums, n, dp))
                return dp[idx] = true;

            // case 2 : 3 equal elements
            if (idx + 2 < n and nums[idx + 2] == nums[idx])

                if (recursion(idx + 3, nums, n, dp))
                    return dp[idx] = true;
        }

        // case 3 : 3 increasing elements
        if (idx + 2 < n and nums[idx + 1] == nums[idx] + 1 and nums[idx + 2] == nums[idx] + 2)
        {
            if (recursion(idx + 3, nums, n, dp))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    bool validPartition(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, -1);

        return recursion(0, nums, n, dp);
    }
};

// Bottom Up DP Solution

class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        int n = nums.size();

        vector<bool> dp(n + 1, false);

        // dp[i] = true if there is a valid partition in the array starting from index i
        dp[0] = true;

        for (int i = 0; i < n; i++)
        {
            int idx = i + 1;
            // case 1 : 2 equal elements
            if (i > 0 and nums[i] == nums[i - 1])
            {
                dp[idx] = dp[idx] or dp[idx - 2];
            }

            if (i > 1 and nums[i] == nums[i - 1] and nums[i] == nums[i - 2])
            {
                dp[idx] = dp[idx] or dp[idx - 3];
            }
            if (i > 1 and nums[i] == nums[i - 1] + 1 and nums[i] == nums[i - 2] + 2)
            {
                dp[idx] = dp[idx] or dp[idx - 3];
            }
        }

        return dp[n];
    }
};