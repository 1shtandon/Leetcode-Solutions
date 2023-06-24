/*
gfg question
*/

#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    vector<string> res;

    void solve(string s, vector<string> &res, int choiceIdx)
    {
        if (choiceIdx == s.size())
        {
            res.push_back(s);
            return;
        }

        solve(s, res, choiceIdx + 1);

        s[choiceIdx] = toupper(s[choiceIdx]);
        solve(s, res, choiceIdx + 1);
    }

    vector<string> permutation(string s)
    {
        solve(s, res, 0);
        return res;
    }
};

int main()
{
    string s = "abc";
    Solution solve;
    vector<string> res = solve.permutation(s);
    for (auto x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}

// TC - O(2^n)
// SC - O(2^n)