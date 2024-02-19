#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, w;
    cin >> n >> w;
    int weights[n];
    ll values[n], dp[w + 1];
    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i < n + 1; ++i) {
        for (int j = w; j >= 0; --j) {
            if (weights[i - 1] <= j) {
                dp[j] = max(dp[j], dp[j - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    cout << dp[w] << "\n";
    return 0;
}