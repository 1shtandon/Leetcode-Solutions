class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int res = 0;
        vector<int> mp(60, 0);

        for (auto &t : time)
        {
            int modulo = t % 60;

            if (modulo == 0)
                res += mp[modulo];
            else
                res += mp[60 - modulo];

            mp[modulo]++;
        }
        return res;
    }
};