class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        /*
            LIS at index i can be:
                * 1 + max(LIS(j)) where 0 < j < i and nums[i] > nums[j]
                * 1 if we cant find such j

            Now the result if max of all LIS, so we use an array
        */
        int n = nums.size();
        vector<int> LIS(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        return *max_element(LIS.begin(), LIS.end());
    }
};

/*
Binary search  - O(nlogn)
*/

class Solution
{
public:
    int lengthOfLIS(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> temp;
        temp.push_back(arr[0]);

        int len = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] > temp.back())
            {
                // arr[i] > the last element of temp array

                temp.push_back(arr[i]);
                len++;
            }
            else
            {
                // replacement step
                int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[ind] = arr[i];
            }
        }

        return len;
    }
};