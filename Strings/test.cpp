#include <bits/stdc++.h>
using namespace std;

int totalOperations (string str, int len) {
    unordered_map<char, int> h;
    for (int i = 0; i < len; i++)
        h [str [i]]++;
    unordered_set<int> hs;
    for (auto i : h)
        hs.insert (i.second);   
    return hs.size ();
}

int main () {
    string str = "abaca";
    int len = str.length ();
    cout << totalOperations (str, len) << endl;
    return 0;
}