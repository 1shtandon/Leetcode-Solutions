/*
Approach:
1. Using set to store the elements of the array as it is sorted.
2. If the element is odd, multiply it by 2.
3. Now, if the maximum element is even, divide it by 2 and insert it in the set.
4. Now, the minimum difference will be the difference between the maximum and minimum element in the set.
5. Repeat the above steps until the maximum element is odd.
6. Return the minimum difference.

Time Complexity: O(nlogn)
Space Complexity: O(n)
*/
class Solution
{
public:
    long long minimumDeviation(vector<int> &nums)
    {
        int n = nums.size();
        set<long long> s;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 1)
                nums[i] *= 2;
            s.insert(nums[i]);
        }
        long long ans = *s.rbegin() - *s.begin();
        while (*s.rbegin() % 2 == 0)
        {
            long long x = *s.rbegin();
            s.erase(x);
            s.insert(x / 2);
            ans = min(ans, *s.rbegin() - *s.begin());
        }
        return ans;
    }
};
