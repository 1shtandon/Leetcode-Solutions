/*
Approach : Set
1. Insert all the elements in a set.
2. Iterate over the array and check if the current element is the starting element of a sequence. This is done by checking if the current element - 1 is present in the set.
3. If yes, then keep incrementing the current element till it is present in the set.
4. Update the maximum length.

Time Complexity - O(n)
Space Complexity - O(n)
*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return n;
        set<int> st;
        for (auto &x : nums)
        {
            st.insert(x);
        }
        int maxLength = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.count(nums[i] - 1) == 0)
            {
                int currentNum = nums[i], currentLength = 1;
                while (st.count(currentNum))
                {
                    currentLength++;
                    currentNum++;
                }
                maxLength = max(maxLength, currentLength);
            }
        }
        return maxLength - 1;
    }
};