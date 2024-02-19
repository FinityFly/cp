#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, k;
ll sum=0;
ll m[200001], f[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> m[i];
    for (int i = 0; i < n; ++i)
        cin >> f[i];
    sort(m, m+n);
    sort(f, f+n);
    if (m[n-1] >= f[n-1] + k) {
        f[n-1] += k;
    } else if (m[n-1] + k <= f[n-1]) {
        m[n-1] += k;
    } else {
        k -= abs(m[n-1]-f[n-1]);
        if (m[n-1] >= f[n-1]) f[n-1] += m[n-1]-f[n-1];
        else m[n-1] += f[n-1]-m[n-1];
        if (k % 2 == 0) {
            m[n-1] += k/2;
            f[n-1] += k/2;
        } else {
            m[n-1] += floor(k/2)+1;
            f[n-1] += floor(k/2);
        }
    }
    for (int i = 0; i < n; ++i) {
        sum += (m[i]*f[i]) % (ll) (1e9 + 7);
    }
    cout << sum % (ll) (1e9 + 7) << "\n";
    return 0;
}