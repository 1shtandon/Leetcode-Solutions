class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            if (asteroids[i] > 0)
            {
                s.push(asteroids[i]);
            }
            else
            {
                while (!s.empty() and s.top() > 0 and s.top() < abs(asteroids[i]))
                {
                    s.pop();
                }

                if (s.empty() or s.top() < 0)
                {
                    s.push(asteroids[i]);
                }
                else if (s.top() == abs(asteroids[i]))
                {
                    s.pop();
                }
            }
        }

        vector<int> ans(s.size());

        for (int i = s.size() - 1; i >= 0; i--)
        {
            ans[i] = s.top();
            s.pop();
        }

        return ans;
    }
};