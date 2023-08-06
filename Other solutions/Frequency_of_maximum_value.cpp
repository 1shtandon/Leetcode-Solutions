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

vector<int> freqMaxValue(vector<int> nums, vector<int> queries)
{
    int n = nums.size();
    int max_freq = 0, max_value = 0;
    vector<int> res(n);

    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > max_value)
        {
            max_value = nums[i];
            max_freq = 1;
        }
        else if (nums[i] == max_value)
        {
            max_freq++;
        }
        res[i] = max_freq;
    }

    vector<int> ans;
    for (int i = 1; i <= queries.size(); i++)
    {
        ans.push_back(res[queries[i - 1]]);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<int> nums = {5, 4, 5, 3, 2};
    vector<int> queries = {1, 2, 3, 4, 5};

    vector<int> res = freqMaxValue(nums, queries);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}