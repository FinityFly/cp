#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, m, temp, far, cnt, dia;
int r[100001];
bool p[100001];
vector<int> adj[100001];

void dfs1(int u, int par) {
    for (int v : adj[u]) {
        if (v == par) continue;
        dfs1(v, u);
        p[u] |= p[v];
    }
    cnt += p[u];
}

void dfs2(int u, int par, int dis) {
    if (dis > dia) {
        dia = dis;
        far = u;
    }
    for (int v : adj[u])
        if (p[v] && v != par)
            dfs2(v, u, dis+1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0, a; i < m; ++i) {
        cin >> a;
        p[a] = true;
        temp = a;
    }
    for (int i = 0, a, b; i < n-1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(temp, -1);
    dfs2(temp, -1, 0);
    dfs2(far, -1, 0);
    cout << 2*(cnt-1) - dia << "\n";
    return 0;
}