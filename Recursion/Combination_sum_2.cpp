/*
Aprroach : Recursion

1. draw recursion tree with choice at every idx to pick or not pick the element

Time Complexity : O(2^n)
Space Complexity : O(n) for recursive stack
*/

class Solution
{
public:
    vector<vector<int>> res;

    void helper(vector<int> &candidates, int target, int idx, vector<int> &ans)
    {

        if (target == 0)
        {
            res.push_back(ans);
            return;
        }

        for (int i = idx; i < candidates.size(); i++)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            if (candidates[i] <= target)
            {
                ans.push_back(candidates[i]);
                helper(candidates, target - candidates[i], i + 1, ans);
                ans.pop_back();
            }
        }

        return;
    }

    vector<vector<int>>
    combinationSum2(vector<int> &candidates, int target)
    {
        int n = candidates.size();

        vector<int> ans;

        int idx = 0;

        sort(candidates.begin(), candidates.end());

        helper(candidates, target, idx, ans);

        return res;
    }
};