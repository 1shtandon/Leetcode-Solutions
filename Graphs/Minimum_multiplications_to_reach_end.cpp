class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        int mod = 100000;
        if (start == end)
        {
            return 0;
        }
        while (!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            for (auto i : arr)
            {
                int n = (node * i) % mod;
                if (steps + 1 < dist[n])
                {
                    dist[n] = steps + 1;
                    if (n == end)
                    {
                        return steps + 1;
                    }
                    q.push({n, steps + 1});
                }
            }
        }
        return -1;
    }
};