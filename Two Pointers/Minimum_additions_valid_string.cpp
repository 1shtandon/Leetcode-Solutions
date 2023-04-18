class Solution
{
public:
    int addMinimum(string &s)
    {
        int n = s.size(), ptr = 0, result = 0;
        while (ptr < n)
        {
            string s2 = s.substr(ptr, 2);
            if (s.substr(ptr, 3) == "abc")
            {
                ptr += 3;
            }
            else if (s2 == "ab" or s2 == "ac" or s2 == "bc")
            {
                ptr += 2;
                result += 1;
            }
            else
            {
                ptr += 1;
                result += 2;
            }
        }
        return result;
    }
};