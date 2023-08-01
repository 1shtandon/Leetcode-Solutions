class Solution
{
public:
    vector<vector<int>> res;

    void recursion(int idx, int n, int k, vector<int> &op)
    {
        if (k == 0)
        {
            vector<int> op1 = op;
            res.push_back(op1);
            return;
        }
        if (idx == n + 1 and k > 0)
        {
            return;
        }

        op.push_back(idx);
        recursion(idx + 1, n, k - 1, op);
        op.pop_back();
        recursion(idx + 1, n, k, op);

        return;
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> v;
        recursion(1, n, k, v);

        return res;
    }
};

// Time Complexity: O(2^N)
// Space Complexity: O(N)