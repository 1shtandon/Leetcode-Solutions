// gfg question

// Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

class Solution
{
public:
    int search(string pat, string txt)
    {
        int len1 = txt.length(), len2 = pat.length();
        int res = 0;

        if (len2 > len1)
            return res;

        unordered_map<char, int> mp1, mp2;

        for (auto &c : pat)
            mp1[c]++;

        int left = 0, right = 0;

        while (right < len1)
        {
            mp2[txt[right]]++;

            if (right - left + 1 < len2)
                right++;

            else if (right - left + 1 == len2)
            {
                if (mp1 == mp2)
                    res++;

                mp2[txt[left]]--;

                if (mp2[txt[left]] == 0)
                    mp2.erase(txt[left]);

                left++;
                right++;
            }
        }
        return res;
    }
};