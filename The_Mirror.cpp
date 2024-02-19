#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    bool prime[501];
    memset(prime, 1, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < 501; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < 501; j += i) {
                prime[j] = false;
            }
        }
    }
    int psa[501];
    psa[0] = 0;
    for (int i = 1; i < 501; ++i) {
        psa[i] = psa[i-1];
        if (prime[i]) {
            ++psa[i];
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cout << psa[b-1] - psa[a-1] << "\n";
    }
    return 0;
}