#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, m;
vector<int> adj[100001];
bool v[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto next: adj[cur]) {
            if (!v[next]) {
                v[next] = true;
                q.push(next);
            }
        }
    }
    if (adj[1].empty())
        v[1] = true;
    for (int i = 1; i <= n; ++i) {
        cout << v[i] ? 1 : 0;
    }
    return 0;
}