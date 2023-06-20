class Solution
{
public:
    void helperRecursion(vector<int> &nums, vector<int> &op, vector<vector<int>> &res)
    {
        if (nums.size() == 0)
        {
            res.push_back(op);
            return;
        }

        vector<int> op1 = op;
        vector<int> op2 = op;

        op2.push_back(nums[0]);
        nums.erase(nums.begin() + 0);

        helperRecursion(nums, op1, res);
        helperRecursion(nums, op2, res);

        return;
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> op;

        helperRecursion(nums, op, res);

        return res;
    }
};