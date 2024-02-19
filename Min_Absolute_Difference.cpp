#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, m, mindiff=INT_MAX;
int a[200001], b[200001];

int bsearcha (int x) { 
    int l=0, r=n, ind=0;
    while (l <= r) {
        int mid = l+(r-l)/2;
        if (a[mid] < x) {
            l = mid+1;
            ind = mid;
        } else {
            r = mid-1;
        }
    }
    return ind;
}

int bsearchb (int x) { 
    int l=0, r=n, ind=0;
    while (l <= r) {
        int mid = l+(r-l)/2;
        if (b[mid] < x) {
            l = mid+1;
            ind = mid;
        } else {
            r = mid-1;
        }
    }
    return ind;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    if (n <= m) {
        for (int i = 0; i < n; ++i) {
            int index = max(0, bsearchb(a[i])-1);
            if (index != m) {
                mindiff = min(mindiff, abs(a[i]-b[index]));
                index++;
                while (abs(a[i]-b[index]) < mindiff) {
                    mindiff = min(mindiff, abs(a[i]-b[index]));
                    index++;
                }
            }
        }
    } else {
        for (int i = 0; i < m; ++i) {
            int index = max(0, bsearcha(b[i])-1);
            if (index != n) {
                mindiff = min(mindiff, abs(b[i]-a[index]));
                index++;
                while (abs(b[i]-a[index]) < mindiff) {
                    mindiff = min(mindiff, abs(b[i]-a[index]));
                    index++;
                }
            }
        }
    }
    cout << mindiff << "\n";
    return 0;
}