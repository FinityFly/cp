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
int v[100001], s[100001], f[100001];

int binary_search(int x) {
    int l=0, h=n, ind=n;
    for (int i = 0; i < 17; ++i) {
        if (s[(l+h)/2] > x)
            h = (l+h)/2;
        else if (s[(l+h)/2] < x)
            l = (l+h)/2;
        else {
            ind = (l+h)/2;
            break;
        }
    }
    for (int i = ind-1; i >= 0; i--) {
        if (s[i] == x) ind = i;
        else break;
    }
    return ind;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        s[i] = v[i];
    }
    sort(s, s+n);
    for (int i = 0; i < n; ++i) {
        f[i] = binary_search(v[i]);
    }
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        if (f[a-1]-1 >= 0 && v[a-1] > v[b-1])
            --f[a-1];
        if (f[b-1]-1 >= 0 && v[a-1] < v[b-1])
            --f[b-1];
    }
    for (int i = 0; i < n; ++i) {
        cout << f[i] << " ";
    }
    return 0;
}