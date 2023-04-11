class Solution
{
public:
    string removeStars(string s)
    {
        string res = "";
        stack<char> st;
        for (auto &c : s)
        {
            if (c != '*')
            {
                st.push(c);
            }
            else
            {
                st.pop();
            }
        }
        if (st.empty())
            return res;
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};