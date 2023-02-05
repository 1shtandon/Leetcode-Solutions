/*
Approach : 
1. Create a map of characters of string p and their frequencies.
2. Create a map of characters of string s and their frequencies.
3. Compare both the maps.
4. If both the maps are equal, push the starting index of the window in the result vector.
5. Now, slide the window by one character.
6. If the character at the starting index of the window is present in the map, then decrease its frequency by 1.
7. If the frequency of the character at the starting index of the window becomes 0, then erase it from the map.
8. Now, increase the frequency of the character at the end of the window by 1.
9. Repeat steps 3 to 8 until the end of the string s is reached.

Time Complexity : O(n)
Space Complexity : O(n)
*/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        int len1 = s.length(), len2 = p.length();

        if (len2 > len1)
            return res;

        unordered_map<char, int> mp1, mp2;

        for (int i = 0; i < len2; i++)
        {
            mp1[s[i]]++;
            mp2[p[i]]++;
        }

        if (mp1 == mp2)
            res.push_back(0);

        int ptr = 0;

        for (int i = len2; i < len1; i++)
        {
            if (mp1[s[ptr]] == 1)
                mp1.erase(s[ptr]);

            else
                mp1[s[ptr]]--;

            ptr++;
            mp1[s[i]]++;

            if (mp1 == mp2)
                res.push_back(ptr);
        }
        return res;
    }
};