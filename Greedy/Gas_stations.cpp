class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total = 0, n = gas.size(), start = 0, rem_gas = 0;

        for (int i = 0; i < n; i++)
        {
            total += gas[i] - cost[i];
            rem_gas += gas[i] - cost[i];
            if (total < 0)
            {
                total = 0;
                start = i + 1;
            }
        }

        if (start == n or rem_gas < 0)
        {
            cout << -1 << endl;
            return -1;
        }

        cout << start << endl;
        return start;
    }
};