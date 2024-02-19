#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int b, c, f[100001], e[100001], p[100001], out=0;
int failed[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> b;
    for (int i = 0; i < b; ++i) {
        cin >> f[i] >> e[i] >> p[i];
    }
    cin >> c;
    for (int i = 0; i < c; ++i) {
        cin >> failed[i];
    }
    sort(failed, failed+c);
    for (int i = 0; i < b; ++i) {
        int cnt = upper_bound(failed, failed+c, e[i]) - lower_bound(failed, failed+c, f[i]);
        cout << e[i] << " : " << f[i] << "\n";
        cout << *upper_bound(failed, failed+c, e[i]) << " - " << *lower_bound(failed, failed+c, f[i]) << " = " << cnt << "\n\n";
        if (cnt == 0)
            out += p[i];
    }
    cout << out << "\n";
    return 0;
}