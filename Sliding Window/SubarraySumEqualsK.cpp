/*
    Approach 1: Hashmap
    1. We maintain a hashmap to store the sum of elements from index 0 to i.
    2. We check if the sum of elements from index 0 to i is equal to k.
    3. Also for every sum, we check if the sum - k exists in the hashmap.
    4. If it exists, then we add the frequency of sum - k to the result.
    5. We repeat the process until the end of the array.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int res = 0;
        unordered_map<int, int> mp;
        for (int i = 0, sum = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum == k)
            {
                res++;
            }
            if (mp.find(sum - k) != mp.end())
            {
                res += mp[sum - k];
            }
            mp[sum]++;
        }
    }
    return res;
};