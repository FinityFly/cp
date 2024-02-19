#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, m, p, q;
map<int, vector<int>> h;

bool dfs(int s, int e) {
    queue<int> q;
    q.push(s);
    vector<bool> visited(n+1);
    visited[s] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto next: h[cur]) {
            if(!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return visited[e];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        h[x].push_back(y);
    }
    cin >> p >> q;
    if (dfs(p, q)) cout << "yes\n";
    else if (dfs(q, p)) cout << "no\n";
    else cout << "unknown\n";
    return 0;
}