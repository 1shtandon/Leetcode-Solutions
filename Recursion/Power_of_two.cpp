class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if ((n % 2 == 1 and n != 1) or n == 0)
            return false;

        if (n == 1)
            return true;

        return isPowerOfTwo(n / 2);
    }
};