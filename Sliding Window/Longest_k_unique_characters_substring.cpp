class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        int len = s.length();
        int res = -1, left = 0, right = 0;
        unordered_map<char, int> mp;

        // implementing variable size sliding window
        while (right < len)
        {
            mp[s[right]]++;

            // if less than k, then continue the window
            if (mp.size() < k)
            {
                right++;
            }

            else if (mp.size() == k)
            {
                res = max(res, right - left + 1);
                right++;
            }

            else if (mp.size() > k)
            {
                while (mp.size() > k)
                {
                    if (mp[s[left]] > 0)
                        mp[s[left]]--;

                    if (mp[s[left]] == 0)
                        mp.erase(s[left]);

                    left++;
                }
                right++;
            }
        }
        return res;
    }
};