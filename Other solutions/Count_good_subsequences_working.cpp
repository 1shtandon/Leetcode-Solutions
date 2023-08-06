#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
//     const int MOD = 1e9 + 7;

// private:
//     pair<vector<long>, vector<long>> factMemo(int n)
//     {
//         vector<long> fact(n + 1), inv(n + 1), invFact(n + 1);

//         fact[0] = inv[0] = 1;
//         invFact[0] = inv[1] = 1;

//         for (int i = 1; i <= n; i++)
//         {
//             if (i >= 2)
//                 inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;

//             fact[i] = fact[i - 1] * i % MOD;
//             invFact[i] = invFact[i - 1] * inv[i] % MOD;
//         }

//         return {fact, invFact};
//     }

//     int combi(int n, int k, vector<long> &fact, vector<long> &invFact)
//     {
//         return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
//     }

// public:
//     int countGoodSubstrings(string s)
//     {
//         int res = 0;
//         vector<int> freq(26);

//         for (auto &x : s)
//             freq[x - 'a']++;

//         int maxFreq = *max_element(freq.begin(), freq.end());

//         auto facts = factMemo(maxFreq);
//         vector<long> fact = facts.first;
//         vector<long> invFact = facts.second;

//         for (int i = maxFreq; i >= 1; i--)
//         {
//             long long temp = 1;

//             for (auto &x : freq)
//                 temp = temp * (1 + combi(x, i, fact, invFact)) % MOD;

//             res = (res + temp - 1) % MOD;
//         }

//         return res;
//     }
// };

class Solution
{
public:
    int countGoodSubsequences(string s)
    {
        constexpr int kMod = 1'000'000'007;
        int ans = 0;
        vector<int> count(26);

        for (const char c : s)
            ++count[c - 'a'];

        const int maxFreq = *max_element(count.begin(), count.end());
        const auto facts = getFactAndInvFact(maxFreq, kMod);

        const auto fact = facts.first;
        const auto invFact = facts.second;

        for (int freq = 1; freq <= maxFreq; ++freq)
        {
            long numSubseqs = 1; // ""
            for (const int charFreq : count)
                if (charFreq >= freq)
                    numSubseqs = (numSubseqs +
                                  numSubseqs * nCk(charFreq, freq, fact, invFact, kMod)) %
                                 kMod;
            ans += numSubseqs - 1; // Minus "".
            ans %= kMod;
        }

        return ans;
    }

private:
    pair<vector<long>, vector<long>> getFactAndInvFact(int n, int kMod)
    {
        vector<long> fact(n + 1);
        vector<long> invFact(n + 1);
        vector<long> inv(n + 1);
        fact[0] = invFact[0] = 1;
        inv[0] = inv[1] = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (i >= 2)
                inv[i] = kMod - kMod / i * inv[kMod % i] % kMod;
            fact[i] = fact[i - 1] * i % kMod;
            invFact[i] = invFact[i - 1] * inv[i] % kMod;
        }
        return {fact, invFact};
    }

    int nCk(int n, int k, const vector<long> &fact, const vector<long> &invFact,
            int kMod)
    {
        return fact[n] * invFact[k] % kMod * invFact[n - k] % kMod;
    }
};

int main()
{
    Solution sol;
    string s = "abcd";
    cout << sol.countGoodSubsequences(s) << endl;
    return 0;
}
