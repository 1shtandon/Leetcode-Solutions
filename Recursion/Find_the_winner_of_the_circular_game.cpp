/*
Approach : Recursion

1. we can observe that the result for n friends can be found by calculating that of n - 1, k
2. for n , we just need to move k more from the winner of n - 1.
3. so f(n) = (f(n- 1) + k)%n
3. result = f(n) + 1, +1 is for 1 based indexing.
*/
class Solution
{
public:
    int solve(int n, int k)
    {
        // base case
        if (n == 1)
            return 0;

        return (solve(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k)
    {
        return solve(n, k) + 1;
    }
};