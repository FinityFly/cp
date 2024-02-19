#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
ll m, n;
char grid[101][101];
ll grid_values[101][101];
ll dp[101][101][3]; // 0 - right, 1 - up, 2 - down
bool dp_solved[101][101][3];

ll maxValue(ll r, ll c, ll last) {
    if (dp_solved[r][c][last]) return dp[r][c][last];
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '*') return -1000000000;
    if (r == m-1 && c == n-1) return grid_values[r][c];
    if (last == 0) {
        dp[r][c][last] = grid_values[r][c] + max(maxValue(r, c+1, 0), max(maxValue(r-1, c, 1), maxValue(r+1, c, 2)));
    }
    if (last == 1) {
        dp[r][c][last] = grid_values[r][c] + max(maxValue(r, c+1, 0), maxValue(r-1, c, 1));
    }
    if (last == 2) {
        dp[r][c][last] = grid_values[r][c] + max(maxValue(r, c+1, 0), maxValue(r+1, c, 2));
    }
    dp_solved[r][c][last] = true;
    return dp[r][c][last];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (cin >> m >> n) {
        memset(dp, 0, sizeof(dp));
        memset(dp_solved, false, sizeof(dp_solved));
        memset(grid_values, 0, sizeof(grid_values));
        if (m != 0 && n != 0) {
            for (ll i = 0; i < m; ++i) {
                for (ll j = 0; j < n; ++j) {
                    cin >> grid[i][j];
                    if (isdigit(grid[i][j])) grid_values[i][j] = grid[i][j] - '0';
                }
            }
            cout << maxValue(m-1, 0, 0) << "\n";
        } else break;
    }
    return 0;
}