#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, m, cnt=0;
bool r[22][22];

void solve(int i, vector<int>& arr) {
    if (i > n) {
        ++cnt;
        return;
    }
    solve(i+1, arr);
    bool conf = false;
    for (int x : arr) {
        if (r[x][i]) {
            conf = true;
        }
    }
    if (!conf) {
        arr.push_back(i);
        solve(i+1, arr);
        arr.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> arr;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        r[a][b] = true;
        r[b][a] = true;
    }
    solve(1, arr);
    cout << cnt << "\n";
    return 0;
}