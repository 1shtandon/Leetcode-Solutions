class Solution
{
public:
    bool ispal(string s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int maxPalindromes(string s, int k)
    {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int len = (j - i) + 1;
                if (len >= k and ispal(s, i, j))
                {
                    ans++;
                    i = j;
                    break;
                }
                if (len > k + 1)
                {
                    break;
                }
            }
        }
        return ans;
    }
};