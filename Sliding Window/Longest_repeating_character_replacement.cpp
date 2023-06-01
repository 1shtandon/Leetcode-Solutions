class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int len = s.length();
        int right = 0, left = 0, res = 0, maxFreqInSubstr = -1;
        unordered_map<char, int> mp;

        // variable size sliding window
        while (right < len)
        {
            mp[s[right]]++;

            maxFreqInSubstr = max(maxFreqInSubstr, mp[s[right]]);

            // if all characters are not same as that of maxFreq, we shrink the window
            if ((right - left + 1) - maxFreqInSubstr > k)
            {
                mp[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};