#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n;
ll k;
int adj[200001], dis[200001];
bool vis[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        adj[i] = x;
    }
    for (int cur = 1; ; cur = adj[cur]) {
        int next = adj[cur];
        if (vis[next]) {
            int cycle = dis[cur] - dis[next] + 1;
            k %= cycle;
        }
        if (k == 0) {
            cout << cur << "\n";
            return 0;
        }
        dis[next] = dis[cur] + 1;
        vis[cur] = true;
        k--;
    }
    return 0;
}