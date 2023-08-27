class Solution
{
public:
    int offset[3] = {-1, 0, 1};
    /* int binarySearch(vector<int> arr, int l, int r, int x)
    {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == x)
                return m;
            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
    bool search(int idx, int prev_jump, vector<int>& stones, int& n) {
        if (idx >= n) return false;
        if (idx == n-1) return true;

        for (int i = 0; i < 3; i++)
        {
            int jump = prev_jump + offset[i];
            int stone = stones[idx] + jump;
            int next_idx = binarySearch(stones, idx+1, n-1, stone);
            if (next_idx == -1) continue;
            bool result = search(next_idx, jump, stones, n);
            if (result) return true;
        }
        return false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false;

        return search(1, 1, stones, n);
    } */

    int binarySearch(vector<int> arr, int l, int r, int x)
    {
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (arr[m] == x)
                return m;
            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
    bool search(int idx, int prev_jump, unordered_map<string, bool> &mp, vector<int> &stones, int &n)
    {
        if (idx >= n)
            return false;
        if (idx == n - 1)
            return true;

        string key = to_string(idx) + "," + to_string(prev_jump);
        if (mp.count(key))
            return mp[key];

        bool result;
        for (int i = 0; i < 3; i++)
        {
            int jump = prev_jump + offset[i];
            int stone = stones[idx] + jump;
            int next_idx = binarySearch(stones, idx + 1, n - 1, stone);
            if (next_idx == -1)
                continue;
            result = search(next_idx, jump, mp, stones, n);
            if (result)
                break;
        }
        return mp[key] = result;
    }

    bool canCross(vector<int> &stones)
    {
        if (stones[1] != 1)
            return false;
        int n = stones.size();
        unordered_map<string, bool> mp;
        return search(1, 1, mp, stones, n);
    }
};