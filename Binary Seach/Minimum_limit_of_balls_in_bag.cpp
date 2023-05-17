class Solution
{
public:
    bool canMakeBags(int bagSize, int maxOperations, vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count += (nums[i] - 1) / bagSize;
        }
        return count <= maxOperations;
    }

    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int n = nums.size();
        // for each value of penalty(bag size) , we check if we can operate on bags in maxOperations
        // minimum penalty is 1 , maximum penalty is max element in nums
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int res = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // check if we can make n bags for penalty mid
            if (canMakeBags(mid, maxOperations, nums))
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return res;
    }
};