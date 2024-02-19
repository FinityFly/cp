#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int a, b;
bool prime[5000001];
vector<int> primes;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    if (a < 2 && b >= 2) a = 2;
    fill(prime, prime+5000001, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i*i <= b; ++i) {
        if (prime[i]) {
            for (int j = i*i; j <= sqrt(b); j += i) 
                prime[j] = false;
        }
    }
    for (int i = 2; i*i <= b; ++i) {
        if (prime[i])
            primes.push_back(i);
    }
    fill(prime, prime+5000001, true);
    for (int i : primes) {
        int l = a/i; // first multiple
        if (l <= 1) 
            l = 2*i;
        else if (a % i) 
            l = (l*i) + i;
        else
            l = l*i;
        for (int j = l; j <= b; j += i)
            prime[j-a] = false;
    }
    for (int i = a; i <= b; ++i) {
        if (prime[i-a])
            cout << i << "\n";
    }
    return 0;
}