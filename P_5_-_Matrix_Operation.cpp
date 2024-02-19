#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, ans=0;
int mat[1501][1501], dp[1501][1501];
bool vis[1501][1501];

int longest_path(int i, int j) {
    if (vis[i][j])
        return dp[i][j];
    int cnt=0;
    if (mat[i+1][j] > mat[i][j]) {
        dp[i][j] = max(dp[i][j], longest_path(i+1, j)+1);
        ++cnt;
    }
    if (mat[i-1][j] > mat[i][j]) {
        dp[i][j] = max(dp[i][j], longest_path(i-1, j)+1);
        ++cnt;
    }
    if (mat[i][j+1] > mat[i][j]) {
        dp[i][j] = max(dp[i][j], longest_path(i, j+1)+1);
        ++cnt;
    }
    if (mat[i][j-1] > mat[i][j]) {
        dp[i][j] = max(dp[i][j], longest_path(i, j-1)+1);
        ++cnt;
    }
    if (cnt == 0)
        dp[i][j] = 0;
    vis[i][j] = true;
    return dp[i][j];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!vis[i][j])
                ans = max(ans, longest_path(i, j));
    cout << ans << "\n";
    return 0;
}