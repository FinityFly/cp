#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int t, a, b, k, m=-1;
int q[101][3], pc[10000001];
bool prime[10000001];

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> q[i][0] >> q[i][1] >> q[i][2];
        m = max(m, q[i][1]+1);
    }
    fill(prime, prime+m, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i*i <= m; ++i) {
        if (prime[i]) {
            for (int j = i*i; j <= m; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= m; ++i) {
        if (prime[i]) {
            for (int j = i; j <= m; j += i) {
                pc[j]++;
            }
        }
    }
    for (int i = 0; i < t; ++i) {
        int cnt=0;
        for (int j = q[i][0]; j <= q[i][1]; ++j) {
            if (pc[j] == q[i][2])
                ++cnt;
        }
        cout << "Case #" << i+1 << ": " << cnt << "\n";
    }
    return 0;
}