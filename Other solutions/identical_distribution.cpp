#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <deque>
#include <numeric>
#include <assert.h>
#include <iomanip>
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

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    int ans = INT_MAX;
    int lim = *max_element(all(a));

    for (int i = 2; i <= lim; i++)
    {
        int cards = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] % i == 0)
                cards += 0;
            else
                cards += (i - a[j] % i);
        }
        if (cards == 0)
        {
            cout << 0 << "\n";
            return 0;
        }

        ans = min(ans, cards);
    }

    cout << ans << "\n";
    return 0;
}