#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair

int n, m;
map<int, vector<pii>> adj;
int maxS[300001];
bool visited[300001];

int binary_search(int x) {
    int l=1, r=n, ind=1;
    while (l <= r) {
        int m = l+(r-l)/2;
        if (maxS[m] <= x) {
            l = m+1;
            ind = m;
        } else {
            r = m-1;
        }
    }
    return ind-1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n-1; ++i) {
        int u, v, s;
        cin >> u >> v >> s;
        adj[u].push_back({v, s});
        adj[v].push_back({u, s});
    }
    queue<pii> q;
    q.push({1, 0});
    visited[1] = true;
    while (!q.empty()) {
        pii curr = q.front();
        q.pop();
        for (auto i : adj[curr.first]) {
            if (!visited[i.first]) {
                q.push({i.first, i.second});
                visited[i.first] = true;
                maxS[i.first] = max(maxS[curr.first], i.second);
            }
        }
    }
    sort(maxS, maxS+n+1);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        cout << binary_search(x) << "\n";
    }
    return 0;
}
