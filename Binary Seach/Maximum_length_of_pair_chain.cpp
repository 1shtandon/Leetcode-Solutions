class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin() , pairs.end());

        vector<int> chain;
        int res = 1;

        chain.push_back(pairs[0][1]);

        for(int i = 1; i < n; i++)
        {
            if(pairs[i][0] > chain.back())
            {
                res++;
                chain.push_back(pairs[i][1]);
            }
            else if (pairs[i][0] < chain.back())
            {
                int newPos = lower_bound(chain.begin() , chain.end() , pairs[i][0]) - chain.begin();
                chain[newPos] = min(chain[newPos] , pairs[i][1]); 
            }
        }

        return res;
    }
};