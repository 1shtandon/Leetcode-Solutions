class Solution
{
public:
    long long minOperations(vector<int> &nums1, vector<int> &nums2, int k)
    {
        if(nums1 == nums2)
            return 0;
        if (k == 0)
            return -1;
        long long n = nums1.size();
        long long res = 0, incr = 0, decr = 0;
        for (long long i = 0; i < n; i++)
        {
            if (nums1[i] > nums2[i])
            {
                long long diff = nums1[i] - nums2[i];
                if (diff % k == 0)
                {
                    incr += diff / k;
                    res += diff / k;
                }
                else
                {
                    return -1;
                }
            }
            if (nums1[i] < nums2[i])
            {
                long long diff = nums2[i] - nums1[i];
                if (diff % k == 0)
                {
                    decr += diff / k;
                    res += diff / k;
                }
                else
                {
                    return -1;
                }
            }
        }
        if (incr == decr)
            return res/2;
        else
            return -1;
    }
};