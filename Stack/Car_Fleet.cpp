/*
Approach : Sort by position
1. We will store the position and the speed of the car in a vector of pairs.
2. Sort the vector of pairs by the position of the car.
3. Calculate the time taken by the car to reach the target.
4. If the time taken by the car to reach the target is greater than the time taken by the previous car to reach the target, then we will increment the number of car fleets.

Time Complexity : O(nlogn)
Space Complexity : O(n)
*/
class Solution {
    public : 
    int carFleet(int target , vector<int> &positions , vector<int> speeds)
    {
        int carFleets = 0;
        int n = positions.size();
        vector<pair<int , int>> cars;
        for(int i = 0 ; i < n ; i++)
        {
            cars.push_back({positions[i] , speeds[i]});
        }
        sort(cars.begin() , cars.end());
        double time = 0;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(time < (double)(target - cars[i].first) / cars[i].second)
            {
                time = (double)(target - cars[i].first) / cars[i].second;
                carFleets++;
            }
        }
        return carFleets;

    }
};