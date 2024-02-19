#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int m, n;
int grid[1001][1001];
bool visited[1001][1001];
queue<pair<int, int>> q;
unordered_set<int> found;
bool isPossible = false;

void findFactors(int a) {
    if (found.find(a) != found.end())
        return;
    for (int i = 1; i <= sqrt(a); ++i) {
        if (a % i == 0) {
            if (i <= m && a/i <= n) {
                q.push(make_pair(i, a/i));
            }
            if (i <= n && a/i <= m) {
                q.push(make_pair(a/i, i));
            }
            found.insert(a);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    if (m == 1 && n == 1) {
        cout << "yes\n";
        return 0;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
        }
    }
    q.push(make_pair(1, 1));
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        if (x == m && y == n) {
            isPossible = 1;
            break;
        }
        q.pop();
        if (visited[x][y])
            continue;
        visited[x][y] = 1;
        findFactors(grid[x][y]);
    }
    if (isPossible)
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}