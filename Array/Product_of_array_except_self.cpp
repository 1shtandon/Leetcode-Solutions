/*
Approach : Using Prefix and Suffix Product

Time Complexity - O(n)
Space Complexity - O(n)
*/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int product = 1, n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            product *= nums[i];
            res[i] = product;
        }
        product = 1;
        for (int i = n - 1; i > 0; i--)
        {
            res[i] = res[i - 1] * product;
            product *= nums[i];
        }
        res[0] = product;
        return res;
    }
};