class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        int len = s1.length();
        if (len == 1)
            return s1 == s2;
        if (s1 == s2)
            return true;
        
        // finding if s2 is a scrambled string of s1
        // s1 is split into two parts x and y now s1 = x + y or s1 = y + x these two options are applied to s1.

        // so base case is when s1 == s2
        // at each case we do s1 = x + y or s1 = y + x using dp
        // so two dimensional dp is used
        vector<vector<bool>> dp(len, vector<bool>(len, false));
    
    }
};