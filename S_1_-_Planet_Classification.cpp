#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    map<int, int> data;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cout << data[a] << "\n";
        ++data[a];
    }
    cout << data.size() << "\n";
    return 0;
}