class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        string res = "";

        int prev = 0;
        for (int i = 0; i < spaces.size(); i++)
        {
            res += s.substr(prev, spaces[i] - prev);
            res += " ";
            prev = spaces[i];
        }

        res += s.substr(prev, s.size() - prev);

        return res;
    }
};