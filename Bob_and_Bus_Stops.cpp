#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, q;
int b[100001];

int bsearch (int x) { 
    int l=1, r=n, ind=1;
    while (l <= r) {
        int m = l+(r-l)/2;
        if (b[m] <= x) {
            l = m+1;
            ind = m;
        } else {
            r = m-1;
        }
    }
    return ind;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(b, b+n);
    for (int i = 0; i < q; ++i) {
        int l, r, cnt=0;
        cin >> l >> r;
        int ub = *upper_bound(b, b+n, r), lb = *lower_bound(b, b+n, l);
        int bsu = bsearch(ub), bsl = bsearch(lb)-1;
        if (ub == 0) bsu = n;
        if (lb == 0) bsl = n;
        cnt = bsu - bsl;
        cout << cnt << "\n";
    }
    return 0;
}