class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();

        int left = 0, right = n - 1;

        if (n == 1 and nums[0] != target)
            return -1;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (nums[mid] == target)
                return mid;

            // this condition means that no deflection in left half
            if (nums[left] <= nums[mid])
            {
                if (target >= nums[left] and target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] and target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};