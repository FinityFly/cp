#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, sum=0, ans=-1;
int diff[10000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int s, f;
        cin >> s >> f;
        ++diff[s];
        --diff[f];
    }
    for (int i = 0; i < 10000001; ++i) {
        sum += diff[i];
        ans = max(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}