/*
Approach : Sliding Window
1. We maintain a window of size s1.length() in s2.
2. We maintain a map to store the frequency of characters in the window.
3. If the map of s1 and the map of the window are equal, then we have found a permutation.
4. We remove the leftmost character from the map and add the rightmost character to the map.
5. We repeat the process until the right pointer reaches the end of the string.
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len2 = s1.length() , len1 = s2.length();
        if (len2 > len1)
            return false;

        unordered_map<char, int> mp1, mp2;

        for (auto &c : s1)
            mp1[c]++;

        int left = 0, right = 0;

        while (right < len1)
        {
            mp2[s2[right]]++;

            if (right - left + 1 < len2)
                right++;

            else if (right - left + 1 == len2)
            {
                if (mp1 == mp2)
                    return true;

                mp2[s2[left]]--;

                if (mp2[s2[left]] == 0)
                    mp2.erase(s2[left]);

                left++;
                right++;
            }
        }
        return false;
    }
};