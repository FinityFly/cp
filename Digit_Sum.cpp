#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n;
ll arr[3001];
ll dp[3001][3001];
bool dp_solved[3001][3001];

ll solve(ll s, ll e) {
    if (dp_solved[s][e]) return dp[s][e];
    if (s==e) return arr[s];
    ll l = arr[s] - solve(s+1, e);
    ll r = arr[e] - solve(s, e-1);
    dp_solved[s][e] = true;
    return dp[s][e] = max(l, r);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(0, n-1) << "\n";
    return 0;
}