class Solution
{
public:
    int ptr1 = 0, maxLength = 0;

    // expand string until palindrome and return such start and end pointers
    void expand(int start, int end, string &s, int &n)
    {
        while (start >= 0 and end < n and s[start] == s[end])
        {
            start--;
            end++;
        }

        if (maxLength < end - start - 1)
        {
            ptr1 = start + 1;
            maxLength = end - start - 1;
        }
    }

    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n == 1)
            return s;

        for (int i = 0; i < n - 1; i++)
        {
            // for both even and odd lengths, considering centres
            expand(i, i, s, n);
            expand(i, i + 1, s, n);
        }

        return s.substr(ptr1, maxLength);
    }
};

// TC: O(n^2)
// SC: O(1)