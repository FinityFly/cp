#include <bits/stdc++.h>
using namespace std;



void solve(){
    int n, k, p;
    cin >> n >> k >> p;
    int dp[51][1501]; // stack, remainder = best beauty value
    memset(dp, 0xc0, sizeof(dp)); // set to infinity
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        memcpy(dp[i+1], dp[i], sizeof(dp[0]));
        int curStackScore = 0;
        for (int j = 0; j < k; ++j) {
            int a;
            cin >> a;
            curStackScore += a;
            for (int l = 0; j+l+1 <= p; ++l) {
                dp[i+1][j+l+1] = max(dp[i+1][j+l+1], dp[i][l] + curStackScore);
            }
        }
    }
    cout << dp[n][p] << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, I=1;
    cin >> T;
    while (T--) {
        cout << "Case #" << I << ": ";
        solve();
        ++I;
    }
    return 0;
}