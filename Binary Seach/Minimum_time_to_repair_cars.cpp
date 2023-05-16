class Solution
{
public:
    long long canRepair(long long time, vector<int> &ranks)
    {
        // within the given time, how many cars can be repaired
        // if for rank r, time required is r * cars^2
        // then for time t, cars repaired = t / r * cars^2
        long long cars = 0;
        for (auto &r : ranks)
        {
            cars += floor(sqrt(time / r));
        }

        return cars;
    }

    long long repairCars(vector<int> &ranks, int cars)
    {
        int n = ranks.size();

        // for each amount of time check if all cars can be repaired
        // minimum time = 0
        // maximum = max element * cars ^2;
        long long low = 0, high = (long long)(*max_element(ranks.begin(), ranks.end())) * ((long long)cars * cars);
        long long res = 0;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long carsRepaired = canRepair(mid, ranks);
            if (carsRepaired >= cars)
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