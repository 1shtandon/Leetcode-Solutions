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
        if (idx == candidates.size())
        {
            if (target == 0)
            {
                res.push_back(ans);
            }
            return;
        }

        // pick the element
        if (candidates[idx] <= target)
        {
            ans.push_back(candidates[idx]);
            helper(candidates, target - candidates[idx], idx, ans);
            ans.pop_back();
        }

        // not pick the element
        helper(candidates, target, idx + 1, ans);

        return;
    }

    vector<vector<int>>
    combinationSum(vector<int> &candidates, int target)
    {
        int n = candidates.size();

        vector<int> ans;

        int idx = 0;

        helper(candidates, target, idx, ans);

        return res;
    }
};


