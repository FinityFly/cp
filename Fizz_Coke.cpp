#include <bits/stdc++.h>
using namespace std;

int m, n;
map<int, string> arr;
string output[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        int a;
        string b;
        cin >> a >> b;
        arr[a] = b;
    }
    for (auto i : arr) {
        for (int j = 0; j <= n; j += i.first) output[j] += i.second;
    }
    for (int i = 1; i <= n; ++i) {
        if (output[i].length() != 0) cout << output[i] << "\n";
        else cout << i << "\n";
    }
    return 0;
}