#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, r, s=0, k=0;
int a[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> a[0];
    for (int i = 1; i < n; ++i) {
        cin >> r;
        a[i] = a[i-1]+r;
    }
    for (int i = 0; i < n; ++i) {
        cin >> r;
        s+=r;
        if (s == a[i]) k=i+1;
    }
    cout << k << "\n";
    return 0;
}