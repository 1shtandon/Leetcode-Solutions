/*
Approach : Sliding Window
1. We maintain a window of size s1.length() in s2.
2. We maintain a map to store the frequency of characters in the window.
3. If the map of s1 and the map of the window are equal, then we have found a permutation.
4. We remove the leftmost character from the map and add the rightmost character to the map.
5. We repeat the process until the right pointer reaches the end of the string.
*/
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.length(), len2 = s2.length();
        if (len2 < len1)
            return false;
        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < len1; i++)
        {
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        if (mp1 == mp2)
            return true;

        int ptr = 0;
        for (int i = len1; i < len2; i++)
        {
            if (mp2[s2[ptr]] == 1)
                mp2.erase(s2[ptr]);
            else
                mp2[s2[ptr]]--;

            mp2[s2[i]]++;
            ptr++;
            if (mp1 == mp2)
                return true;
        }
        return false;
    }
};