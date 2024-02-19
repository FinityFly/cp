#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
/*

*/
int r, c, k;
bool cats[26][26];
int dp[26][26];
bool dp_solved[26][26];

int solve(int row, int col) {
    if(dp_solved[row][col])
        return dp[row][col];
    if(row == r && col == c)
        return 1;
    int ans = 0;
    if (row+1 <= r && cats[row + 1][col] == false)
        ans += solve(row + 1, col);
    if (col+1 <= c && cats[row][col + 1] == false)
        ans += solve(row, col + 1);
    dp_solved[row][col] = true;
    return dp[row][col] = ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        cats[a][b] = true;
    }
    cout << solve(1, 1) << "\n";
    return 0;
}