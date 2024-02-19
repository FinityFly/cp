#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int t, m=-1;
int q[100001][3];
int f[100001];
int psa[634][100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> q[i][0] >> q[i][1] >> q[i][2];
        m = max(m, q[i][2]+1);
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; j += i) {
            f[j]++;
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < 635; ++j) {
            psa[j][i] = psa[j][i-1];
        }
        psa[f[i]][i]++;
    }
    for (int i = 0; i < t; ++i) {
        cout << psa[q[i][0]][q[i][2]] - psa[q[i][0]][q[i][1]-1] << "\n";
    }
    return 0;
}