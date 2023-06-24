/*
Approach 1: Using recursion with extra space

For each index, we have n choices, so TC: O(n^n)
as we choose , we mark it as visited
once we are done with the recursion, we unmark it as visited and also pop last inserted element

draw the recursion tree for better understanding

TC: O(n*n!)
SC: O(n)
*/

class Solution
{
public:
    vector<vector<int>> res;

    void solve(vector<int> &nums, vector<int> &op, int n, vector<bool> &visited)
    {
        if (op.size() == n)
        {
            res.push_back(op);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                op.push_back(nums[i]);
                solve(nums, op, n, visited);
                op.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> op;
        vector<bool> visited(n, false);

        solve(nums, op, n, visited);

        return res;
    }
};

/*
Approach 2: Using recursion without extra space , using swap

TC: O(n*n!)
SC: O(1) , ignoring the space required for storing the result
*/

class Solution
{
public:
    vector<vector<int>> res;

    void solve(vector<int> &nums, int idx, int n)
    {
        if (idx == n)
        {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < n; i++)
        {
            swap(nums[i], nums[idx]);
            solve(nums, idx + 1, n);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        solve(nums, 0, n);
        return res;
    }
};