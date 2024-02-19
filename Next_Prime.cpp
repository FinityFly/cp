#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
ll n;

bool isPrime(ll n) {
    if (n <= 1) return false;
    for (ll i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = n; i < 2000000012; ++i) {
        if (isPrime(i)) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}