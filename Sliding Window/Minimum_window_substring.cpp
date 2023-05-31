class Solution
{

private:
    bool isCovered(unordered_map<char, int> &mp1, unordered_map<char, int> &mp2)
    {
        for (auto &x : mp1)
        {
            if (mp2[x.first] < x.second)
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> mp1, mp2;
        for (auto &x : t)
            mp1[x]++;

        int left = 0, right = 0;
        int min_len = INT_MAX;
        int start = 0;

        // when all letters covered, store the range of substring
        // now we make window minimum until the conditions are met
        
        while (right < s.size())
        {
            if (mp1.find(s[right]) != mp1.end())
            {
                mp2[s[right]]++;
            }
            right++;

            while (isCovered(mp1, mp2))
            {
                if (right - left < min_len)
                {
                    min_len = right - left;
                    start = left;
                }

                if (mp1.find(s[left]) != mp1.end())
                {
                    mp2[s[left]]--;
                }
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};