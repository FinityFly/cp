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
ll arr[1000001], psa[1000002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    psa[0] = 0;
    for (int i = 1; i <= n; ++i) psa[i] = psa[i-1] + arr[i-1];
    for (int i = n; i > 0; --i) {
        for (int j = 0; j+i <= n; ++j) {
            if ((psa[j+i]-psa[j]) % k == 0) {
                cout << (j+i)-j << "\n";
                return 0;
            }
        }
    }
    return 0;
}