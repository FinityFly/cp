#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
/*

*/
ll n, k, sum=0, last;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (ll i = 1; i < n; ++i) {
        sum += i;
        cout << i << " ";
        if (i == n-1) last = i;
    }
    ll a = ceil(sum/k);
    ll b=1;
    while ((a+b)*k < last) ++b;
    cout << (a*k)-sum << "\n";
    return 0;
}