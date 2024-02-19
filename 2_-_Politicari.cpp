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
ll k;
int adj[501][501], d[501][501];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> adj[i][j];
        }
    }
    int pre=1, cur=2;
    k--;
    d[1][2] = 1;
    while (true) {
        int next = adj[cur][pre];
        if (d[cur][next] > 0) {
            int cycle = d[pre][cur] - d[cur][next] + 1;
            k %= cycle;
        }
        if (k == 0) {
            cout << pre << "\n";
            return 0;
        }
        d[cur][next] = d[pre][cur] + 1;
        k--;
        pre = cur;
        cur = next;
    }
    return 0;
}