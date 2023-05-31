class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int n = s.length();
        int ans = 0;
        for (int numUniqueChars = 1; numUniqueChars <= 26; numUniqueChars++)
        {
            int charFreq[26] = {0};
            int numCharsWithFreqAtLeastK = 0, numCharsWithFreq = 0;
            for (int right = 0, left = 0; right < n; right++)
            {
                int currChar = s[right] - 'a';
                charFreq[currChar]++;
                if (charFreq[currChar] == 1)
                {
                    numCharsWithFreq++;
                }
                if (charFreq[currChar] == k)
                {
                    numCharsWithFreqAtLeastK++;
                }
                while (numCharsWithFreq > numUniqueChars)
                {
                    int leftChar = s[left] - 'a';
                    charFreq[leftChar]--;
                    if (charFreq[leftChar] == k - 1)
                    {
                        numCharsWithFreqAtLeastK--;
                    }
                    if (charFreq[leftChar] == 0)
                    {
                        numCharsWithFreq--;
                    }
                    left++;
                }
                if (numCharsWithFreq == numUniqueChars && numCharsWithFreq == numCharsWithFreqAtLeastK)
                {
                    ans = max(ans, right - left + 1);
                }
            }
        }
        return ans;
    }
};