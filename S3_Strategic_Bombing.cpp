#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
/*

*/

map<char, vector<char>> adj;
vector<string> roads;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a;
    while (cin >> a) {
        if (a != "**") {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
            roads.push_back(a);
        } else break;
    }
    int cnt=0;
    for (auto road: roads) {
        queue<char> q;
        map<char, bool> visited;
        q.push('A');
        visited['A'] = true;
        while (!q.empty()) {
            char cur = q.front();
            q.pop();
            for (auto next : adj[cur]) {
                if (cur == road[0] && next == road[1] || cur == road[1] && next == road[0])
                    continue;
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        if (!visited['B']) {
            cout << road << "\n";
            cnt++;
        }
    }
    cout << "There are " << cnt << " disconnecting roads.\n";
    return 0;
}