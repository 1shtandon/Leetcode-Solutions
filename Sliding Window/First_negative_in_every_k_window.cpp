// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
// gfg question

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<long long> res;
    long long left = 0, right = 0;
    queue<long long> q;
    while (right < N)
    {
        if (A[right] < 0)
        {
            q.push(A[right]);
        }
        if (right - left + 1 < K)
        {
            right++;
        }
        else if (right - left + 1 == K)
        {
            if (q.empty())
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(q.front());
                if (A[left] == q.front())
                {
                    q.pop();
                }
            }
            left++;
            right++;
        }
    }
    return res;
}