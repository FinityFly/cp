#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, k;
int dp[251][251];

int solve(int pieces, int people) {
    if (pieces < people) {
        return 0;
    } else {
        if (dp[pieces][people]) {
            return dp[pieces][people];
        } else {
            return dp[pieces][people] = solve(pieces - people, people) + solve(pieces - 1, people - 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        dp[i][1] = dp[i][i] = 1;
    cout << solve(n, k) << "\n";
    return 0;
}