/*
Approach : Greedy
1. Sort the array
2. Now we can complete all projects if we can do the one with maximum milestones.
3. So we need to find how much milestones of maximum we can complete.
4. For project with x milestones, we need atleast x-1 milestones of other projects to fit the rule.
5. Think!

Time Complexity: O(nlogn)
Space Complexity: O(1)
*/

class Solution
{
public:
    long long numberOfWeeks(vector<int> &milestones)
    {
        sort(milestones.begin(), milestones.end());
        long long maxWeeks = 0, sum = 0, n = milestones.size(), last = milestones[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            sum += milestones[i];
        }
        if (sum >= last - 1)
        {
            maxWeeks = sum + last;
        }
        else
        {
            maxWeeks = 2 * sum + 1;
        }
        return maxWeeks;
    }
};