class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfitidx = 0, maxProfit = 0, n = prices.size();
        for (int i = 1; i < n; i++)
        {
            int temp = prices[i] - prices[maxProfitidx];
            if (temp > maxProfit)
                maxProfit = temp;
            else if (temp < 0)
                maxProfitidx = i;
        }
        return maxProfit;
    }
};