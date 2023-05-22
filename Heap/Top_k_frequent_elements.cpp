class Solution
{
public:
    vector<int> topKFrequent(vector<int> &arr, int k)
    {
        vector<int> res;
        int n = arr.size();
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto it : m)
        {
            pq.push({it.second, it.first});
        }
        for (int i = 0; i < k; i++)
        {
            pair<int, int> top = pq.top();
            res.push_back(top.second);
            pq.pop();
        }
        return res;
    }
};