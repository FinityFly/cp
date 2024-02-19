#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, a, b, maxn=-1, ans=-1;
int p[101], pr[101];

int bsearch (int x) { 
    int l=0, r=n, ind=1;
    while (l <= r) {
        int m = l+(r-l)/2;
        if (p[m] <= x) {
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
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pr[n-1-i] = p[i];
    }
    sort(p, p+n);
    sort(pr, pr+n, greater<int>());
    cin >> a >> b;
    int i = bsearch(*upper_bound(p, p+n, a));
    if (a < p[0]) {
        if (a % 2 == 0) {
            ans = (p[i]-(a+1) > maxn) ? a+1 : ans;
            maxn = max(maxn, p[i]-(a+1));
        } else {
            ans = (p[i]-a > maxn) ? a : ans;
            maxn = max(maxn, p[i]-a);
        }
    } else {
        if (a % 2 == 0) {
            ans = (p[i]-(a+1) > maxn) ? a+1 : ans;
            maxn = max(maxn, p[i]-(a+1));
        } else {
            if (p[i]-a > maxn && p[i]-a < p[i-1]-a) {
                ans = a;
                maxn = p[i]-a;
            } else if (p[i-1]-a > maxn && p[i]-a > p[i-1]-a) {
                ans = a;
                maxn = p[i-1]-a;
            }
        }
    }
    int j = bsearch(*lower_bound(pr, pr+n, b, greater<int>()));
    if (b > p[n-1]) {
        if (b % 2 == 0) {
            ans = ((b-1)-p[j] > maxn) ? b-1 : ans;
            maxn = max(maxn, (b-1)-p[j]);
        } else {
            ans = (b-p[j] > maxn) ? b : ans;
            maxn = max(maxn, b-p[j]);
        }
    } else {
        if (b % 2 == 0) {
            ans = ((b-1)-p[j] > maxn) ? b-1 : ans;
            maxn = max(maxn, (b-1)-p[j]);
        } else {
            if (p[j]-b > maxn && p[j]-b < p[j+1]-b) {
                ans = b;
                maxn = p[j]-b;
            } else if (p[j+1]-b > maxn && p[j]-b > p[j+1]-b) {
                ans = b;
                maxn = p[j+1]-b;
            }
        }
    }
    for (int i = 0; i < n-1; ++i) {
        int av = (p[i] + p[i+1])/2;
        if (av >= a && av <= b) {
            if (av % 2 == 0) {
                ans = ((av-1)-p[i] > maxn) ? av-1 : ans;
                maxn = max(maxn, (av-1)-p[i]);
            } else {
                ans = (av-p[i] > maxn) ? av : ans;
                maxn = max(maxn, av-p[i]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}