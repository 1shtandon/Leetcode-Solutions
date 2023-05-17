class Solution
{
public:
    bool canPlaceBalls(int force, int m, vector<int> &positions)
    {
        int prev = positions[0];
        int count = 1;
        for (int i = 1; i < positions.size(); i++)
        {
            if (positions[i] - prev >= force)
            {
                count++;
                prev = positions[i];
            }
        }
        return count >= m;
    }

    int maxDistance(vector<int> &position, int m)
    {
        // sort the position vector to greedily place the balls
        sort(position.begin(), position.end());
        int n = position.size();
        // minimum force is 1 , maximum force is distance between first and last ball
        int low = 1, high = position[n - 1] - position[0];
        int res = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // check if we can place m balls for force mid
            if (canPlaceBalls(mid, m, position))
            {
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return res;
    }
};