class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        /*
        n = 1 -> 0
        n = 2 -> 01
        n = 1 -> 0110
        n = 1 -> 01101001
        n = 1 -> 0110100110010110


        for nth row, elements are 2^n - 1
        also half output for n is same is n - 1, and rest half is just opposite

        for recursion

        base case = if n == 1 or  k == 1 we return 0
        */

        if (n == 1 or k == 1)
            return 0;

        int mid = pow(2, n - 1) / 2;

        // if k is less equal to mid , then result same as previous row
        if (k <= mid)
        {
            return kthGrammar(n - 1, k);
        }

        // else we return opposite of what we get from previous row for first half, i.e k - mid
        return !kthGrammar(n - 1, k - mid);
    }
};