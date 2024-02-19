#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, m, sum=0, cnt=0;
int diff[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        ++diff[l-1];
        --diff[r];
    }
    for (int i = 0; i < n; ++i) {
        sum += diff[i];
        if (sum % 2 == 1)
            ++cnt;
    }
    cout << cnt << "\n";
    return 0;
}