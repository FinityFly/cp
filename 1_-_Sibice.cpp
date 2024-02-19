#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, w, h;
double m;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> w >> h;
    m = sqrt(w*w+h*h);
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        if (l <= m) cout << "DA\n";
        else cout << "NE\n";
    }
    return 0;
}