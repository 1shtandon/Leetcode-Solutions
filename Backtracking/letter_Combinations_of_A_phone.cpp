class Solution
{
public:
    vector<string> res;
    unordered_map<char, vector<char>> mp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}};

    void recursion(string &s, int idx, int n, string &digits)
    {
        // base case
        if (idx == n)
        {
            string copy = s;
            res.push_back(copy);
            return;
        }

        for (auto it : mp[digits[idx]])
        {
            s += it;
            recursion(s, idx + 1, n, digits);
            s.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits)
    {
        int n = digits.size();
        if (n == 0)
            return {};

        string op = "";

        recursion(op, 0, n, digits);
        return res;
    }
};