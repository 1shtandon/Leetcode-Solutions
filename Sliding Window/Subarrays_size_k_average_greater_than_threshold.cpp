class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int n = arr.size();
        int left = 0, right = 0, sum = 0, res = 0;

        while (right < n)
        {
            sum += arr[right];
            if (right - left + 1 < k)
            {
                right++;
            }

            else if (right - left + 1 == k)
            {
                if (sum / k >= threshold)
                    res++;

                sum -= arr[left];
                left++;
                right++;
            }
        }
        return res;
    }
};