#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int r, c, q;
bool rows[1001], columns[1001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            char a;
            cin >> a;
            if (a == 'X') {
                rows[i] = true;
                columns[j] = true;
            }
        }
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        if (rows[y-1] || columns[x-1]) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}