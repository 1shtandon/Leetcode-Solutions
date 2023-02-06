/*
Approach : Sliding Window

1. Maintain a left and right pointer for window.
2. To store the different fruits, maintain a map.
3. If the size of map exceeds 2, then move the left pointer ahead by removing the previous value
4. The max of this sliding window is the result


Time Complexity : O(n)
Space Complexity : O(n)
*/

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size(), res = 0;
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        while (right < n)
        {
            mp[fruits[right]]++;
            while (mp.size() > 2)
            {
                if (mp[fruits[left]] == 1)
                    mp.erase(fruits[left]);
                else
                    mp[fruits[left]]--;

                left++;
            }

            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};