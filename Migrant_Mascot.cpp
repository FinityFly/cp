#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
/*

*/
int n, m;
map<int, vector<pii>> adj;
int minValue[200001];

void prim(int a) {
	int weight[n+1];
	bool visited[n+1];
	fill(mst, mst+n+1, 0);
	fill(visited, visited+n+1, false);
	fill(weight, weight+n+1, -1);
	weight[a] = 0;
	mst[a] = -1;
	for (int i = 0; i < n-1; ++i) {
		int u = maxWeight(weight, visited);
		visited[u] = true;
		if (u == a)
		    mst[u] = a;
		for (int v = 0; v < adj[u].size(); ++v) {
		    if (visited[adj[u][v].first] == false && weight[adj[u][v].first] < adj[u][v].second) {
                mst[adj[u][v].first] = u;
			    weight[adj[u][v].first] = adj[u][v].second;
		    }
		}
	}
	printMST(mst, weight);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    prim(1);
    // cout << "0\n";
    // for (int i = 1; i < n; ++i) {

    // }
    return 0;
}