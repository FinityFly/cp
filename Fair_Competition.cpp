#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int m, n, out=0;
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    for (auto it = cnt.rbegin(); it != cnt.rend(); ++it) {
        if (it->second <= n) {
            out += it->second;
            n -= it->second;
        } else break;
    }
    cout << out << "\n";
    return 0;
}