#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> nums, int mid)
{
    int n = nums.size();
    int overflow = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        nums[i] += overflow;
        overflow = max(0, nums[i] - mid);
    }

    return overflow <= 0;
}

int minimize_max_value(vector<int> arr)
{
    int n = arr.size();
    int l = 1, r = *max_element(arr.begin(), arr.end());
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (check(arr, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return ans;
}

int main()
{
    vector<int> arr = {5, 15, 19};
    cout << minimize_max_value(arr) << endl;
    return 0;
}
