class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 2)
        {
            reverse(nums.begin() , nums.end());
            return;
        }

        // finding pivot, no from right, smaller than its next
        int i = n - 2;
        while(i >= 0 and nums[i] >= nums[i + 1])
        {
           i--;
        }

        if(i < 0)
        {
            reverse(nums.begin() , nums.end());
            return;
        }

        // find new pivot, number from right greater than pivot
        int j = n - 1;
        while(j > i and nums[j] <= nums[i])
        {
            j--;
        }

        swap(nums[i] , nums[j]);

        reverse(nums.begin() + i + 1 , nums.end());
    }
};
