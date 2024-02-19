#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n;
int factor_freq[10007];

void getPrimeFactors(int n) {
    vector<int> f;
    while (n % 2 == 0) {
        ++factor_freq[2];
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            ++factor_freq[i];
            n = n/i;
        }
    }
    if (n > 2)
        ++factor_freq[n];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int t = 0; t < 5; ++t) {
        cin >> n;
        fill(factor_freq, factor_freq+10007, 0);
        for (int i = 2; i <= n; ++i) {
            getPrimeFactors(i);
        }
        cout << "2^" << factor_freq[2];
        for (int i = 3; i < n; ++i) {
            if (factor_freq[i] != 0) {
                cout << " * " << i << "^" << factor_freq[i];
            }
        }
        cout << "\n";
    }
    return 0;
}