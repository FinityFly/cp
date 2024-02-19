#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n;
string s;
int dp[2][1000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    if (s[0] == 'A')
        dp[1][0] = 1;
    else
        dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'A') {
            dp[0][i] = dp[0][i-1];
            dp[1][i] = min(dp[0][i-1], dp[1][i-1])+1;
        } else {
            dp[1][i] = dp[1][i-1];
            dp[0][i] = min(dp[0][i-1], dp[1][i-1])+1;
        }
    }
    cout << dp[0][n-1] << "\n";
    return 0;
}