#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n;
int r[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
        if (i != 0) {
            int a=r[0], b=r[i];
            if (a == 0) {
                cout << floor(a/b) << "/1" << "\n";
            } else {
                for (int i = a; i > 1; --i) {
                    if (a % i == 0 && b % i == 0) {
                        a /= i; b /= i;
                    }
                }
                cout << a << "/" << b << "\n";
            }
        }
    }
    return 0;
}