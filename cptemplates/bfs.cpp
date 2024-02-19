#include <bits/stdc++.h>
using namespace std;

/*

*/

void bfs(int a) {
    queue<int> q;
    vector<int> v;
    q.push(a);
    while (!q.empty())
    {
        int a = q.front();
        q.pop();

        for (auto j = g[a].begin(); j != g[a].end(); j++)
        {
            if (!v[*j])
            {
                v[*j] = true;
                q.push(*j);
            }
        }
        cout << a << "  ";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    return 0;
}