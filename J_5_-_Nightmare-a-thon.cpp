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
int r[500001], l_max[500001], r_max[500001], l_freq[500001], r_freq[500001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    for (int i = 1; i <= n; ++i) {
        l_max[i] = max(l_max[i-1], r[i-1]);
        r_max[n-i+1] = max(r_max[n-i+2], r[n-i]);
        if (r[i-1] > l_max[i-1])
            l_freq[i] = 1;
        else if (r[i-1] == l_max[i-1])
            l_freq[i] = l_freq[i-1]+1;
        else
            l_freq[i] = l_freq[i-1];
        if (r[n-i] > r_max[n-i+2])
            r_freq[n-i] = 1;
        else if (r[n-i] == r_max[n-i+2])
            r_freq[n-i] = r_freq[n-i+1]+1;
        else
            r_freq[n-i] = r_freq[n-i+1];
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << max(l_max[a-1], r_max[b+1]) << " ";
        if (l_max[a-1] < r_max[b+1])
            cout << r_freq[b];
        else if (l_max[a-1] > r_max[b+1])
            cout << l_freq[a-1];
        else
            cout << l_freq[a-1] + r_freq[b];
        if (i != q-1)
            cout << "\n";
    }
    
    return 0;
}