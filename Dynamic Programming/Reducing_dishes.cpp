/*
For every element, consider we are starting making dishes from this index (after sorting). The maximum answer will get returned in the end.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int n = satisfaction.size(), res = 0;
        sort(satisfaction.begin(), satisfaction.end());
        for (int i = 0; i < n; i++)
        {
            int sum = 0, time = 1;

            for (int j = i; j < n; j++)
            {
                sum += time * satisfaction[j];
                time++;
            }
            res = max(res, sum);
        }

        return res;
    }
};