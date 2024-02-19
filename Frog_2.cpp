#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, k;
int h[100001];
int dp[100001];
bool dp_solved[100001];

int solve(int a) {
    if (a == n) return 0;
    if (dp_solved[a]) return dp[a];
    for (int i = 1; i <= k && a+i <= n; ++i)
        dp[a] = min(dp[a], solve(a+i)+abs(h[a]-h[a+i]));
    dp_solved[a] = true;
    return dp[a];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    fill(dp, dp+n, INT_MAX);
    cout << solve(1) << "\n";
    return 0;
}