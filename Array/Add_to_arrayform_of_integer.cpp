class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int n = num.size();
        vector<int> res;
        int ptr = n - 1, carry = 0;

        while (ptr >= 0 or carry > 0 or k > 0)
        {
            int sum = carry;
            if (ptr >= 0)
            {
                sum += num[ptr];
                ptr--;
            }
            if (k > 0)
            {
                int rem = k % 10;
                sum += rem;
                k /= 10;
            }

            carry = sum / 10;
            res.push_back(sum % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
