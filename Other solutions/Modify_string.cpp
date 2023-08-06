class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int n = s.length();
        vector<bool> vis(26, false);
        vector<int> mp(26, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            mp[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (vis[s[i] - 'a'])
                continue;

            while (!st.empty() and st.top() < (s[i] - 'a') and mp[st.top()] > i)
            {
                vis[st.top()] = false;
                st.pop();
            }
 
            vis[s[i] - 'a'] = true;
            st.push(s[i] - 'a');
            
        }
        string res = "";
        while (!st.empty())
        {
            res += (st.top() + 'a');
            st.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};