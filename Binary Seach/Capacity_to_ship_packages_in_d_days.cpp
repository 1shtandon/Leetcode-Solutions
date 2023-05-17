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
        lowCap = *max_element(weights.begin(), weights.end());
        highCap = accumulate(weights.begin(), weights.end(), 0);

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