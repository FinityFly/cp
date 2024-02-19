#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
ll t, n, s;
ll diff, cnt;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        diff=(((n+1)*n)/2)-s;
        if (diff % 2 == 0) cnt = min((diff/2)-1, n-(diff/2));
        else cnt = min(floor(diff/2), n-(floor(diff/2)));
        cout << cnt << "\n";
    }
    return 0;
}