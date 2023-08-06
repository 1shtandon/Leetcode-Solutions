#include <bits/stdc++.h>
#define watch(x)                    \
    for (int i = 0; i < sz(x); i++) \
    cout << x[i] << "\n"
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define ll long long int
#define ld long double
#define show(x) cout << x[i] << " "
using namespace std;

#define MAX 100000
#define MOD 1000000007

// initialize traingle of size max + 1 x max + 1 with 0

vector<vector<long long>> makeTriangle(long long freq)
{
    vector<vector<long long>> triangle(freq + 1, vector<long long>(freq + 1, 0));
    // initialize first row of triangle
    triangle[0][0] = 1;

    // initialize first column of triangle
    for (int i = 1; i <= freq; i++)
        triangle[i][0] = 1;

    // fill the triangle using recursive formula
    for (int i = 1; i <= freq; i++)
        for (int j = 1; j <= i; j++)
            triangle[i][j] = (triangle[i - 1][j - 1] + triangle[i - 1][j]) % MOD;

    return triangle;
}

long long countGoodSubsequences(string s)
{
    unordered_map<char, int> mp;
    for (auto &x : s)
        mp[x]++;
    long long res = 0, max_freq = 0;

    for (auto &x : mp)
        max_freq = max(max_freq, (long long)x.second);
    

    vector<vector<long long>> triangle = makeTriangle(max_freq);

    for (int i = max_freq; i >= 1; i--)
    {
        long long temp = 1;
        for (auto &x : mp)
        {
            temp = temp * (1 + triangle[x.second][i]) % MOD;
        }
        res = (res + temp - 1) % MOD;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> s;

    cout << countGoodSubsequences(s) << "\n";
    return 0;
}