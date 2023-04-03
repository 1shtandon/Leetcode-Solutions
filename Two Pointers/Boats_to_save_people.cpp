class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int boats = 0;
        int n = people.size();
        sort(people.begin(), people.end());
        int start = 0, end = n - 1;
        while (start <= end)
        {
            if (people[start] + people[end] > limit)
            {
                end--;
            }
            else
            {
                end--;
                start++;
            }
            boats++;
        }
        return boats;
    }
};