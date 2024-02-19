#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, v, ind=0, c=-1;
int w[2001];
int dp[10001], out[100001];

struct query {
    int c, l, i;
} query;

struct query q[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> v;
    for (int i = 0; i < n; ++i) cin >> w[i];
    for (int i = 0; i < v; ++i) {
        cin >> q[i].c >> q[i].l;
        q[i].i = i;
        c = max(c, q[i].c);
    }
    sort(q, q+v, [](auto &lhs, auto &rhs) {
        return lhs.l < rhs.l;
    });
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int t = 0; t < v; ++t) {
        int l = q[t].l;
        for (int i = ind; i < l; ++i) {
            for (int j = w[i]; j <= c; ++j) {
                dp[j] = min(dp[j], dp[j-w[i]]+1);
            }
        }
        if (dp[q[t].c] == 0x3f3f3f3f) out[q[t].i] = -1;
        else out[q[t].i] = dp[q[t].c];
        ind = max(ind, l);
    }
    for (int i = 0; i < v; ++i) {
        cout << out[i] << "\n";
    }
    return 0;
}