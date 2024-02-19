#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>

/*

*/
int n, d;

int dijk(int a, int b) {
    bool visited[n]
    dist[a] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, a});
    while (!q.empty()) {
        pii x = q.top(); q.pop();
        if (visited[x.second]) continue;
        visited[x.second] = true;
        for (pii& node : adj[x.second]) {
            if (dist[node.first] > x.first + node.second) {
                dist[node.first] = x.first + node.second;
                q.push({dist[node.first], node.first});
            }
        }
    }
    return dist[b];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> d;
    cout << dijk(d) << "\n";
    return 0;
}