#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector< vector<ll> > vvll;
typedef vector< pair<ll, ll> > vpll;
typedef unordered_map<ll, ll> mll;
typedef unordered_set<ll> sll;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e-1; i >= (ll)s; i--)
#define TRAV(a, c) for (auto a : c)
#define all(x) x.begin(), x.end()

ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
template <class T>
string to_string(T s, T e) {
    if (s == e) return "[]";
    string ret = "[" + to_string(*s++);
    while (s != e) ret += ", " + to_string(*s++);
    return ret + "]";
}

#define MM 100001
#define MOD 998244353
#define PI 3.1415926535897932384626433832795

#define FASTIO ;
// #define PRECISION ;
// #define FILE ;

#define SINGLE ;
// #define MULTIPLE ;

ll n;

void solve() {
    cin >> n;

}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#endif
#ifdef PRECISION
    cout << fixed << setprecision(10);
#endif
#ifdef FILE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef SINGLE
    solve();
#endif
#ifdef MULTIPLE
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        solve();
    }
#endif
}



/*

#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed, but often included

// Modulo constant
const long long MOD = 998244353;

// Function for modular exponentiation (base^exp % MOD)
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Function for modular inverse (n^-1 % MOD) using Fermat's Little Theorem
long long inv(long long n) {
    return power(n, MOD - 2);
}

// Using a sufficiently large size for MAX_ITEMS. Max sum of A,B,C,D is 4*1000=4000 for typical constraints.
// Let's assume problem constraints like A,B,C,D <= 1000, so total items <= 4000.
const int MAX_ITEMS_SUM = 4000; 
std::vector<long long> fact(MAX_ITEMS_SUM + 5); // Add a small buffer
std::vector<long long> inv_fact(MAX_ITEMS_SUM + 5);

// Precompute factorials and inverse factorials
void precompute_factorials() {
    fact[0] = 1;
    inv_fact[0] = 1; 
    
    for (int i = 1; i <= MAX_ITEMS_SUM + 4; i++) { // Iterate up to the max needed index
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    inv_fact[MAX_ITEMS_SUM + 4] = inv(fact[MAX_ITEMS_SUM + 4]);
    
    for (int i = MAX_ITEMS_SUM + 3; i >= 1; i--) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;
    }
}

// Function to compute nCr % MOD
long long nCr_mod(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    // C(n,r) = n! / (r! * (n-r)!)
    long long num = fact[n];
    long long den = (inv_fact[r] * inv_fact[n-r]) % MOD;
    return (num * den) % MOD;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute_factorials(); 

    int A_count, B_count, C_count, D_count;
    std::cin >> A_count >> B_count >> C_count >> D_count;

    if (A_count == 0) {
        // Conditions involving apples are vacuous. Only P_Or < P_Gr matters.
        // This means arranging B oranges, C bananas, D grapes such that oranges are before grapes.
        // Choose C positions for bananas from B+C+D total spots: C(B+C+D, C).
        // Remaining B+D spots: B oranges, then D grapes (1 way).
        long long result = nCr_mod(B_count + C_count + D_count, C_count);
        std::cout << result << std::endl;
        return 0;
    }

    // For A_count > 0:
    // Sum Form 1 (B_count + 1 terms): sum_{k=0 to B} C(A+k-1, k) * C(B-k+C+D, C)
    // Sum Form 2 (D_count terms in sum part): C(A+B+C+D, A+C) - sum_{j=0 to D-1} C(j+C, C) * C(A+B+D-j-1, A-1)
    // We choose the formula with fewer terms. A-1 is used in C(N,K), C(A+k-1, A-1) is also fine.
    
    if (D_count < B_count + 1) {
        // Use Sum Form 2 (sum over D_count terms)
        long long main_term = nCr_mod(A_count + B_count + C_count + D_count, A_count + C_count);
        long long subtractive_sum = 0;

        for (int j = 0; j < D_count; ++j) { // j from 0 to D_count-1
            long long term_sum1 = nCr_mod(j + C_count, C_count);
            // C(A+B+D-j-1, A-1) or C(A+B+D-j-1, B+D-j) are equivalent
            long long term_sum2 = nCr_mod(A_count + B_count + D_count - j - 1, A_count - 1); 
            subtractive_sum = (subtractive_sum + term_sum1 * term_sum2) % MOD;
        }
        
        long long final_result = (main_term - subtractive_sum + MOD) % MOD; 
        std::cout << final_result << std::endl;
    } else {
        // Use Sum Form 1 (sum over B_count+1 terms)
        long long total_sum = 0;
        for (int k = 0; k <= B_count; ++k) { // k from 0 to B_count
            long long term1 = nCr_mod(A_count + k - 1, k); // C(A+k-1, k)
            long long term2 = nCr_mod(B_count - k + C_count + D_count, C_count);
            total_sum = (total_sum + term1 * term2) % MOD;
        }
        std::cout << total_sum << std::endl;
    }

    return 0;
}

*/