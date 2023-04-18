class Solution
{
public:
    string helper(string &s, int start, int end)
    {
        if (start > end)
            return "";
        else if (start == end)
            return string(1, s[start]);
        else if (s[start] == s[end])
        {
            string temp = helper(s, start + 1, end - 1);
                        
            if (temp.length() == end - start - 1)
                return s[start] + temp + s[end];
            else
                return temp;
        }
        else
        {
            string temp1 = helper(s, start + 1, end);
            string temp2 = helper(s, start, end - 1);
            if (temp1.length() > temp2.length())
                return temp1;
            else
                return temp2;
        }
    } 


    string longestPalindrome(string s)
    {
        int n = s.length();
        // solving using recursion
        return helper(s, 0, n - 1);
    }
};