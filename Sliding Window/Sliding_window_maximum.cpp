class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        list<int> ls = {INT_MIN};
        vector<int> res;

        // implementing sliding window
        int left = 0, right = 0;
        while (right < n)
        {
            // if we found a greaeter number than remove all previous elements, as they are of no use
            while (!ls.empty() and ls.back() < nums[right])
            {
                ls.pop_back();
            }

            ls.push_back(nums[right]);

            if (right - left + 1 < k)
                right++;

            else if (right - left + 1 == k)
            {
                // now we need to get the ans , as window is complete
                // also slide the window afterwards via left ptr

                res.push_back(ls.front());

                // if front of list was the starting of window, then remove it
                if (ls.front() == nums[left])
                {
                    ls.pop_front();
                }
                left++;
                right++;
            }
        }
        return res;
    }
};


/*
Priority queue approach 
*/


class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<pair<int , int>> pq;
        vector<int> res;

        // implementing sliding window
        int left = 0, right = 0;
        while (right < n)
        {
            pq.push({nums[right] , right});            

            if (right - left + 1 < k)
                right++;

            else if (right - left + 1 == k)
            {
                while(pq.top().second < left)
                    pq.pop();
                
                res.push_back(pq.top().first);

                left++;
                right++;
            }
        }
        return res;
    }
};