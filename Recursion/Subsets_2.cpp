class Solution
{
public:
    void helperRecursion(vector<int> nums, int start, vector<int> op, map<vector<int>, int> &mp, vector<vector<int>> &res)
    {
        if (start >= nums.size())
        {
            if (mp[op] == 0)
            {
                res.push_back(op);
                mp[op]++;
            }
            return;
        }

        helperRecursion(nums, start + 1, op, mp, res);

        if (start > 0 && nums[start] == nums[start - 1] && mp[op] == 0)
            return;

        op.push_back(nums[start]);
        helperRecursion(nums, start + 1, op, mp, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> op;

        map<vector<int>, int> mp;

        helperRecursion(nums, 0, op, mp, res);

        return res;
    }
};



// Backtracking approach

class Solution
{
public:
    void helperRecursion(vector<int> &nums, int start, vector<int> &op, vector<vector<int>> &res)
    {
        res.push_back(op);
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            op.push_back(nums[i]);
            helperRecursion(nums, i + 1, op, res);
            op.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> op;
        helperRecursion(nums, 0, op, res);
        return res;
    }
};