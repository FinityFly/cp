#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int m, n, j, cnt=0;
int diff[100002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> j;
    for (int i = 0; i < j; ++i) {
        int x, y, k;
        cin >> x >> y >> k;
        diff[x] += k;
        diff[y+1] -= k;
    }
    for (int i = 2; i <= m; ++i) {
        diff[i] += diff[i-1];
    }
    for (int i = 1; i <= m; ++i) {
        if (diff[i] < n) ++cnt;
    }
    cout << cnt << "\n";
    return 0;
}