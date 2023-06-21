class Solution
{
public:
    long long check(int x, vector<int> &nums, vector<int> &cost)
    {
        int n = nums.size();
        long long total_cost = 0LL;

        for (int i = 0; i < n; i++)
        {
            total_cost += 1LL * abs(nums[i] - x) * cost[i];
        }

        return total_cost;
    }

    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        int n = nums.size();

        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        long long res = LLONG_MAX;

        while (left <= right)
        {

            int mid = left + (right - left) / 2;

            long long op1 = check(mid, nums, cost);
            long long op2 = check(mid + 1, nums, cost);

            res = min({res, op1, op2});
            
            if (op2 > op1)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return res;
    }
};