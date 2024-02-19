#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, m;
ll ans=0;
ll arr[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    for (int i = 0; i < n; ++i) {
        ans += upper_bound(arr, arr+i, m-arr[i]) - arr;
    }
    cout << ans << "\n";
    return 0;
}