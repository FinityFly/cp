#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
ll n, l=1, h=2e9+1;

int main() {
    string r;
    cout << (l+h)/2 << "\n";
    while (true) {
        cin >> r;
        if (r == "SINKS")
            l = (l+h)/2;
        else if (r == "FLOATS")
            h = (l+h)/2;
        else break;
        cout << (l+h)/2 << "\n";
    }
    return 0;
}