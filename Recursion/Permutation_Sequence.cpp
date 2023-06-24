class Solution
{
public:
    string res;

    // swap technique wont work here as we need to maintain the order, so we will use recursion with visited array

    void helper(string &s, int k, int &count, string &ans, vector<bool> &visited)
    {

        if (ans.size() == s.size())
        {
            count++;
            if (count == k)
            {
                res = ans;
            }
            return;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                ans += s[i];
                helper(s, k, count, ans, visited);
                ans.pop_back();
                visited[i] = false;
            }
        }

        return;
    }

    string getPermutation(int n, int k)
    {
        string s = "";
        for (int i = 1; i <= n; i++)
        {
            s += to_string(i);
        }

        int count = 0;

        string ans = "";

        vector<bool> visited(n, false);

        helper(s, k, count, ans, visited);

        return res;
    }
};