/*
Approach: Binary Search
1. The least capacity required is the maximum weight in the array.
2. The highest capacity required is the sum of all weights in the array.
3. Now, we can use binary search to find the minimum capacity required.
4. We can check if a given capacity can ship all the weights in the given number of days.
5. If yes, we can reduce the capacity and check if we can ship all the weights in the given number of days.
6. If no, we can increase the capacity and check if we can ship all the weights in the given number of days.

Time Complexity: O(nlogm) , where n is the number of weights and m is the sum of all weights.
Space Complexity: O(1)
*/

class Solution
{
public:
    bool canShip(vector<int> &weights, int days, int capacity)
    {
        int daysReq = 1, currCap = capacity;

        for (auto &w : weights)
        {
            if (currCap - w < 0)
            {
                daysReq += 1;
                currCap = capacity;
            }
            currCap -= w;
        }

        return daysReq <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int lowCap = 0, highCap = 0, res = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            lowCap = max(lowCap, weights[i]);
            highCap += weights[i];
        }

        res = highCap;

        while (lowCap <= highCap)
        {
            int midCap = (lowCap + highCap) / 2;
            if (canShip(weights, days, midCap))
            {
                res = min(res, midCap);
                highCap = midCap - 1;
            }
            else
            {
                lowCap = midCap + 1;
            }
        }

        return res;
    }
};