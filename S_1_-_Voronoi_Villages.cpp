#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n;
double ans=INT_MAX;
double v[101], b[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v, v+n);
    for (int i = 0; i < n-1; ++i) {
        b[i] = (v[i] + v[i+1])/2;
    }
    for (int i = 0; i < n-2; ++i) {
        ans = min(ans, b[i+1]-b[i]);
    }
    cout << fixed << setprecision(1) << ans << "\n";
    return 0;
}