class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int n = answerKey.size();

        int left = 0, right = 0;

        int maxLen = 0;

        int count = 0;

        // continuous window of false, and count of true
        while (right < n)
        {
            if (answerKey[right] == 'T')
            {
                count++;
            }

            while (count > k)
            {
                if (answerKey[left] == 'T')
                {
                    count--;
                }

                left++;
            }

            maxLen = max(maxLen, right - left + 1);

            right++;
        }

        left = 0, right = 0;

        count = 0;

        // continuous window of true, and count of false

        while (right < n)
        {
            if (answerKey[right] == 'F')
            {
                count++;
            }

            while (count > k)
            {
                if (answerKey[left] == 'F')
                {
                    count--;
                }

                left++;
            }

            maxLen = max(maxLen, right - left + 1);

            right++;
        }

        return maxLen;
    }
};