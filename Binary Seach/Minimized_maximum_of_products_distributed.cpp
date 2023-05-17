class Solution
{
public:
    bool canDistribute(int k, int n, vector<int> &quantities)
    {
        // chcek that can we distribute products among n stores with k as maximum quantity
        for (auto &q : quantities)
        {
            n -= ceil(q / (k * 1.0));
        }

        return n >= 0;
    }

    int minimizedMaximum(int n, vector<int> &quantities)
    {
        // for every quantiity, of products, we need to check if it can be distributed among n stores
        // minimum quantity = 0 , maximum = max element

        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        int res = 0;

        // applying binary search on the quantity to find minimum quantity
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (canDistribute(mid, n, quantities))
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return res;
    }
};