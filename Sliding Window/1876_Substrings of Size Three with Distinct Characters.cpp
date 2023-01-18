/*
Approach : Sliding Window
1. We maintain a window of size 3.
2. We maintain a map to store the frequency of characters in the window.
3. If the size of the map is 3, then we have a good substring.
4. We remove the leftmost character from the map and add the rightmost character to the map.
5. We repeat the process until the right pointer reaches the end of the string.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int goodSubstrings = 0, len = s.length();
        int left = 0, right = 0;
        unordered_map<char, int> mp;
        while (right < len)
        {
            mp[s[right]]++;
            if (right - left + 1 < 3)
            {
                right++;
            }
            else if (right - left + 1 == 3)
            {
                if (mp.size() == 3)
                {
                    goodSubstrings++;
                }
                mp[s[left]]--;
                if (mp[s[left]] == 0)
                {
                    mp.erase(s[left]);
                }
                left++;
                right++;
            }
        }
        return goodSubstrings;
    }
};