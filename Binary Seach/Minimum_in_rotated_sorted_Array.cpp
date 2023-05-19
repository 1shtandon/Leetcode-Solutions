class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();

        // since we need a logn time complexity for the approach, binary search is optimal
        // when rotation occurs,we must a violation in the increasing order of array,
        // we need to find this point of violation in logn

        // minimum value of index = 0, maximum = n - 1;
        int left = 0, right = n - 1;

        // now this is the only condition which means that array is rotated to reach original order.
        if (right == 0 or nums[left] < nums[right])
            return nums[0];

        while (left <= right)
        {
            int mid = (left + right) / 2;

            // checking for violation around mid
            if (nums[mid] > nums[mid + 1])
                return nums[mid + 1];

            else if (nums[mid - 1] > nums[mid])
                return nums[mid];

            // if no violation in left half then discard left and viceversa
            if (nums[mid] > nums[0])
                left = mid + 1;
            else
                right = mid - 1;
        }

        // MAX possible answer ;_;
        return 5001;
    }
};