class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        int left = 0, right = 0, res = 0;
        unordered_map<char, int> mp;

        while (right < n)
        {
            mp[s[right]]++;

            // until a valid window exists, there are substrings till the end
            while (mp['a'] and mp['b'] and mp['c'])
            {
                // for every such window from left, add substrings from right till end
                res += n - right;
                // moving window ahead
                mp[s[left]]--;
                left++;
            }

            right++;
        }

        return res;
    }
};