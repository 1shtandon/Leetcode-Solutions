class Solution
{
public:
    vector<string> res;

    /*
        For each character in the string, we have two choices:
        1. Either we put a space after it
        2. Or we don't put a space after it

        Draw the recursion tree for "ABC" for clear understanding

        TC - O(2^n)
        SC - O(2^n)

    */

    void solve(string s, vector<string> &res, int choiceIdx)
    {
        if (choiceIdx == s.size() - 1)
        {
            res.push_back(s);
            return;
        }

        solve(s, res, choiceIdx + 1);

        s.insert(choiceIdx + 1, " ");
        solve(s, res, choiceIdx + 2);
    }

    vector<string> permutation(string s)
    {
        solve(s, res, 0);
        sort(res.begin(), res.end());
        return res;
    }
};
