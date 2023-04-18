class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int n = word1.length(), m = word2.length();
        int ptr1 = 0, ptr2 = 0;
        string res = "";
        while (ptr1 < n and ptr2 < m)
        {
            res += word1[ptr1];
            ptr1++;
            res += word2[ptr2];
            ptr2++;
        }

        if (n > m)
        {
            res += word1.substr(ptr1, n);
        }
        else if (m > n)
        {
            res += word2.substr(ptr2, m);
        }
        return res;
    }
};