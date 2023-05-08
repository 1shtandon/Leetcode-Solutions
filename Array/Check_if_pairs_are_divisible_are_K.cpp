class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        // we can create a map having remainder and their frequency for complete array
        int n = arr.size();
        map<int, int> mp;
        for (auto &x : arr)
        {
            mp[((x % k) + k) % k]++;
        }

        // now for each element in map, there are following conditions
        // 1. if remainder is 0, then frequency must be even to make pairs
        // 2. the frequency of remainder = frequencey of(k - remainder)
        // 3. the k - remainder must be available in the map for every remainder.
        // if any of these conditions are not true, then we'll return false

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            // condition 1
            if (it->first == 0)
            {
                if (it->second % 2 != 0)
                    return false;
            }

            // condition 2
            else if (mp.find(k - it->first) == mp.end())
                return false;

            // condition 3
            else if (it->second != mp[k - it->first])
                return false;
        }
        return true;
    }
};