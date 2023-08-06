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

long long helper(vector<int> s, vector<int> e, vector<int> a, int d, int n, int k)
{
    long long res = 0;
    pair<int, pair<int, int>> p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].first = a[i];
        p[i].second.first = s[i];
        p[i].second.second = e[i];
    }

    sort(p, p + n, greater<pair<int, pair<int, int>>>());
    int mins = *min_element(all(s));
    int maxe = *max_element(all(e));
    for (int i = mins; i <= maxe; i++)
    {
        long long gain = 0, ptr = k;
        for (auto &x : p)
        {
            if (i >= x.second.first and i <= x.second.second)
            {
                gain += x.first;
                ptr--;
            }

            if (!ptr)
                break;
        }

        res = max(res, gain);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int d, n, k;
    cin >> d >> n >> k;
    vector<int> s(n);
    for (auto &x : s)
        cin >> x;
    vector<int> e(n);
    for (auto &x : e)
        cin >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long res = 0;

    res = helper(s, e, a, d, n, k);

    cout << res << "\n";
    return 0;
}