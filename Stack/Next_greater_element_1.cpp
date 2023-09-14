class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums2.size();

        // storing next greater elements for whole array
        vector<int> nextGreaterElements(n);
        // storing indexes in a map
        unordered_map<int, int> indexes;
        // stack for implentation
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            // now till there is a smaller element at stack top, pop it
            while (!st.empty() and st.top() <= nums2[i])
            {
                st.pop();
            }

            // if stack becomes empty then -1
            if (st.empty())
                nextGreaterElements[i] = -1;
            else
                nextGreaterElements[i] = st.top();

            st.push(nums2[i]);

            indexes[nums2[i]] = i;
        }

        // now filling the query results in the first array itself and returning
        for (auto &x : nums1)
        {
            x = nextGreaterElements[indexes[x]];
        }

        return nums1;
    }
};






#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    vector<long long>
    nextLargerElement(vector<long long> arr, int n)
    {

        vector<long long> v(n, -1);

        long long mx = arr[n - 1];
 
        // Iterate over the array from right to left.
        for (int i = n - 2; i >= 0; i--) {

            if (arr[i + 1] > arr[i]) {
                v[i] = arr[i + 1];
            }
            else {

                if (v[i + 1] > arr[i]) {
                    v[i] = v[i + 1];
                }
                else if (mx > arr[i]) {

                    int k = i + 1;

                    while (arr[k] <= arr[i]) {
                        k++;
                    }
                    v[i] = arr[k];
                }
                else {

                    v[i] = -1;
                }
            }
            // Update the maximum element seen so far.
            mx = max(arr[i], mx);
        }

        return v;
    }
};