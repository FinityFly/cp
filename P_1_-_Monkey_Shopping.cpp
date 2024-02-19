#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int a, b, c, d;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c >> d;
    if (a < b && c >= d) {
        cout << "Go to the grocery store\n";
    } else if (a >= b && c < d) {
        cout << "Go to the pharmacy\n";
    } else if (a < b && c < d) {
        cout << "Go to the department store\n";
    } else {
        cout << "Stay home\n";
    }
    
    return 0;
}