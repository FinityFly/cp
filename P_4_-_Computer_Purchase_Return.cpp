#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int t, n, b;
map< int, vector<int> > costs, values;
int dp[7][3001];
bool dp_solved[7][3001];

int bestValue(int type, int remainder) {
    if (dp_solved[type][remainder]) {
        return dp[type][remainder];
    }
    if (type == t+1) {
        return 0;
    }
    int best = -1;
    for (int i = 0; i < costs[type].size(); ++i) {
        if (costs[type][i] <= remainder) {
            best = max(best, values[type][i] + bestValue(type + 1, remainder - costs[type][i]));
        }
    }
    dp_solved[type][remainder] = true;
    return dp[type][remainder] = best;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << "boot\n";
    cin >> t >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        costs[z].push_back(x);
        values[z].push_back(y);
    }
    cin >> b;
    cout << bestValue(1, b) << "\n";
    return 0;
}