class Solution
{
public:
    vector<int> res;

    void solve(vector<int> arr, vector<int> op)
    {
        if (arr.size() == 0)
        {
            int sum = 0;
            for (auto &x : op)
                sum += x;

            res.push_back(sum);

            return;
        }

        vector<int> op1 = op;
        vector<int> op2 = op;

        // one with including the first element
        op2.push_back(arr[0]);

        arr.erase(arr.begin() + 0);

        solve(arr, op1);
        solve(arr, op2);

        return;
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> op;

        solve(arr, op);

        return res;
    }
};