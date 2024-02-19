#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
/*

*/
int t, n, k, w;
int weights[30002];
int dp[502][30002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int x = 0; x < t; ++x) {
        fill(weights, weights+30002, 0);
        for (int i = 0; i < 502; ++i) {
            fill(dp[i], dp[i]+30002, 0);
        }
        cin >> n >> k >> w;
        weights[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> weights[i];
        }
        for (int i = 1; i <= k; ++i) {
            int a = 0;
            for (int j = 1; j <= n; ++j) {
                if (j < w + 1) {
                    a += weights[j];
                    dp[i][j] = a;
                } else {
                    a += weights[j]-weights[j-w];
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j-w] + a);
                }
            }
        }
        cout << dp[k][n] << "\n";
    }
    return 0;
}