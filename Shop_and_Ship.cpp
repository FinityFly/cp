#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int n, t, k, d;
map<int, vector<pair<int, int>>> adj;
vector<pair<int, int>> cost;

int dijk(int a) {
    set<pair<int, int>> pq;  // <current best distance to the node, node number>
    vector<int> dist(n+1);
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[a] = 0;
    pq.insert({0, a});
    while(!pq.empty()) {
        pair<int, int> cur = *pq.begin();
        pq.erase(pq.begin());
        for (auto next: adj[cur.second]) {
            if (cur.first + next.second < dist[next.first]) {
                dist[next.first] = cur.first + next.second;
                pq.insert({dist[next.first], next.first});
            }
        }
    }
    int minCost = INT_MAX;
    for (int i = 0; i < k; ++i) {
        minCost = min(minCost, dist[cost[i].first] + cost[i].second);
    }
    return minCost;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    for (int i = 0; i < t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        cost.push_back({a, b});
    }
    cin >> d;
    cout << dijk(d) << "\n";
    return 0;
}