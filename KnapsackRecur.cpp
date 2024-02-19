#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int n, w;
vector<ll> weights, values;
ll dp[1005][1005];
bool dp_solved[1005][1005];

ll best_option(ll index, ll remainder) {
    if (dp_solved[index][remainder]) {
        return dp[index][remainder];
    }
    if (index == n) {
        return 0;
    }

    ll option_leave = best_option(index + 1, remainder);
    ll option_take = -1;
    if (remainder - weights[index] >= 0) {
        option_take = values[index] + best_option(index + 1, remainder - weights[index]);
    }

    dp_solved[index][remainder] = true;
    dp[index][remainder] = max(option_leave, option_take);
    return max(option_leave, option_take);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> w;
    weights.resize(n), values.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }

    cout << best_option(0, w) << '\n';
    
    // Bottom up method
//     for (int i = n - 1; i >= 0; --i) {
//         for (int j = 0; j <= w; ++j) {
//             ll option_leave = best_option(i + 1, j);
//             ll option_take = -1;
//             if (j - weights[i] >= 0) {
//                 option_take = values[i] + best_option(i + 1, j - weights[i]);
//             }
//             dp[i][j] = max(option_leave, option_take);
//         }
//     }

    // cout << dp[0][w] << '\n';

    return 0;
}