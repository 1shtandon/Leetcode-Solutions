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

int throwTheBall(vector<int> receiver, long long k)
{
    int n = receiver.size();

    // detecting cycle occuring at which index
    int slow = 1, fast = 1;
    do
    {
        slow = receiver[slow - 1];
        fast = receiver[receiver[fast - 1] - 1];
        k--;
        if (k == 0)
            return slow;

    } while (slow != fast);

    int cycle_len = 0, start = slow;
    do
    {
        slow = receiver[slow - 1];
        cycle_len++;
    } while (slow != start);

    k %= cycle_len;

    while (k--)
    {
        slow = receiver[slow - 1];
    }

    return slow;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    vector<int> receiver = {2, 4, 1, 5, 3};
    long long k = 8;

    cout << throwTheBall(receiver, k) << endl;
    return 0;
}