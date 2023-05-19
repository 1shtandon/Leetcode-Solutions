// simple sliding window approach

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int res = 0, left = 0, right = 0;
        set<char> st;

        while (right < n)
        {
            if (st.find(s[right]) == st.end())
            {
                st.insert(s[right]);
                res = max(res, right - left + 1);
                right++;
            }
            else
            {
                st.erase(s[left]);
                left++;
            }
        }

        return res;
    }
};