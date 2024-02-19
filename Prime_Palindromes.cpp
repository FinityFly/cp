#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
    
    for (int i = 0; i < 5; ++i) {
        int l, u;
        cin >> l >> u;

    }
    
    return 0;
}