class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        int n = nums.size();

        if (n == 0)
            return res;

        if (n == 1)
        {
            res.push_back(to_string(nums[0]));
            return res;
        }

        int start = nums[0];
        int end = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == end + 1)
            {
                end = nums[i];
            }
            else
            {
                if (start == end)
                {
                    res.push_back(to_string(start));
                }
                else
                {
                    res.push_back(to_string(start) + "->" + to_string(end));
                }
                start = nums[i];
                end = nums[i];
            }

            if (i == n - 1)
            {
                if (start == end)
                {
                    res.push_back(to_string(start));
                }
                else
                {
                    res.push_back(to_string(start) + "->" + to_string(end));
                }
            }
        }

        return res;
    }
};