#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int c, r, x=0, y=0, a, b;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> r;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        else {
            if (x + a > c) x = c;
            else if (x + a < 0) x = 0;
            else x += a;
            if (y + b > r) y = r;
            else if (y + b < 0) y = 0;
            else y += b;
            cout << x << " " << y << "\n";
        }
    }
    
    return 0;
}