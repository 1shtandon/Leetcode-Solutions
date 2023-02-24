/*
Approach : Greedy and Priority Queue
Time Complexity : O(nlogn)
Space Complexity : O(n)
*/
class Solution
{
public:
   int findMaximizedCapital(int k, int W, vector<int> &Profits, vector<int> &Capital)
   {
      int n = Profits.size();
      vector<pair<int, int>> v;
      for (int i = 0; i < n; i++)
      {
         v.push_back({Capital[i], Profits[i]});
      }
      sort(v.begin(), v.end());
      priority_queue<int> pq;
      int i = 0;
      while (k--)
      {
         while (i < n && v[i].first <= W)
         {
            pq.push(v[i].second);
            i++;
         }
         if (pq.empty())
            break;
         W += pq.top();
         pq.pop();
      }
      return W;
   }
};
