#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
ll a, b, n;
ll m[34] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
ll dp[35];
bool dp_solved[35];

ll solve(ll cur) {
    if (cur == n+13) return 1;
    if (dp_solved[cur]) return dp[cur];
    ll cnt=0;
    for (int i = cur+1; i < n+14; ++i) {
        if (m[i] - m[cur] >= a && m[i] - m[cur] <= b) cnt += solve(i);
    }
    dp_solved[cur] = true;
    return dp[cur] = cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> n;
    for (int i = 14; i < n+14; ++i) {
        cin >> m[i];
    }
    sort(m, m+14+n);
    cout << solve(0) << "\n";
    return 0;
}