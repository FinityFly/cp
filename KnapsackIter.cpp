#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
First set all array values to zero
Base case at dp[0][0]
Copy subarray from previous row
If taking object overflows the weight limit, skip to next object
Replace current value if new updated value is better
dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i])
                            ^ no double counting of current object's previous values
                                    ^ no double counting of current object's weight penalty
                                            ^ add value of included current object
Return last value, dp[m][n]
m - used all (though not necessarily all) of the backpack's capacity
n - considered until the last object
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
 
    for (int i = 0; i < n; ++i) {
        for (int j = w; j >= 0; --j) {
            if (weights[i] <= j) {
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
            }
        }
    }
    cout << dp[w] << "\n";
    return 0;
}