class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int len = s.length();
        int count = 0, maxCount = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < len; i++)
        {
            if (i >= k and vowels.count(s[i - k]))
                count--;

            if (vowels.count(s[i]))
                count++;

            maxCount = max(count, maxCount);
        }

        return maxCount;
    }
};