#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, sum=0, m=-1;
vector<pii> adj[100001];

void dfs(int c, int p, int d) {
    m = max(m, d);
    for (auto next: adj[c])
        if (next.first != p)
            dfs(next.first, c, d+next.second);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        sum += c;
    }
    dfs(0, -1, 0);
    cout << 2*sum-m << "\n";
    return 0;
}