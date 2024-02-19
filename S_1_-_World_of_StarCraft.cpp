#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, m, k, cnt=0;
char r[1001];
int p[1001];

int find(int node) {
    while (p[node] != node) {
        node = p[node];
    }
    return node;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> r;
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (r[a-1] != r[b-1])
            continue;
        cout << a << " - " << b << " | " << find(a-1) << " - " << find(b-1) << "\n";
        p[find(b-1)] = find(a-1);
    }
    cout << "\n";
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        cout << x << " - " << y << " | " << find(x-1) << " - " << find(y-1) << "\n";
        if (find(x-1) == find(y-1))
            ++cnt;
    }
    cout << cnt << "\n";
    return 0;
}