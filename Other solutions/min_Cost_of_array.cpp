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

int minCost(vector<int> a, int n)
{
    int res = 0;
    int diff = INT_MIN;
    int ptr = 0;

    // finding maximum difference between two consecutive elements
    for (int i = 0; i < n - 1; i++)
    {
        if (diff < abs(a[i] - a[i + 1]))
        {
            diff = abs(a[i] - a[i + 1]);
            ptr = i;
        }
    }

    // now where the differenc is maximum, we will add the element as median of two elements

    int median = (a[ptr] + a[ptr + 1]) / 2;

    // now we will add the cost of array
    for (int i = 0; i < n - 1; i++)
    {
        if (i == ptr)
        {
            res += pow(a[i] - median, 2);
            res += pow((a[i + 1] - median), 2);
        }

        else
        {
            res += pow(abs(a[i] - a[i + 1]), 2);
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    vector<int> a = {1, 3, 5, 2, 10};
    int n = a.size();

    cout << minCost(a, n) << endl;
    return 0;
}