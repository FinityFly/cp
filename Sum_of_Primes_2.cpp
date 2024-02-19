#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, m=-1;
int q[100001][2], psa[100001];
bool prime[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> q[i][0] >> q[i][1];
        m = max(m, q[i][1]);
    }
    fill(prime, prime+100001, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i*i <= m; ++i) {
        if (prime[i]) {
            for (int j = i*i; j <= m; j += i) 
                prime[j] = false;
        }
    }
    psa[0] = 0;
    for (int i = 1; i <= m; ++i) {
        psa[i] = psa[i-1];
        if (prime[i]) {
            psa[i] += i;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << psa[q[i][1]] - psa[q[i][0]-1] << "\n";
    }
    return 0;
}