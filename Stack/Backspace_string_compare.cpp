class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st1, st2;
        for (auto &x : s)
        {
            if (x == '#' and st1.empty())
            {
                continue;
            }
            else if (x == '#')
                st1.pop();
            else
                st1.push(x);
        }
        for (auto &y : t)
        {
            if (y == '#' and st2.empty())
            {
                continue;
            }
            else if (y == '#')
                st2.pop();
            else
                st2.push(y);
        }

        return st1 == st2;
    }
};