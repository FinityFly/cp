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
typedef map<ll, ll> mll;

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
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define FASTIO ;
// #define PRECISION ;
// #define FILE ;

// #define SINGLE ;
#define MULTIPLE ;
// #define GOOGLE ;

/*
We need to crack a password.
The password consists of  two bit strings a and b, each of which has a length of n. In one operation, Lady Bug can choose any index 2≤i≤n and perform one of the following actions:

swap(ai, b_i−1) (swap the values of a_i and b_i−1), or
swap(b_i, a_i−1) (swap the values of b_i and a_i−1).

Lady Bug can perform any number of operations. The password is considered cracked if she can ensure that the first string consists only of zeros.
Help her understand whether or not she will be able to save the unfortunate Dasha.

The first line of each test case contains one integer n (2≤n≤2⋅105) — the length of the bit strings of the password.

The next two lines contain the bit strings of length n, a and b, which represent the password. Each of the strings contains only the characters 0 and '1'.

sample input:
4
3
000
000
6
010001
010111
5
10000
01010
2
11
00

sample output:
YES
YES
NO
YES
*/

ll n;

void solve() {
    string a, b;
    cin >> n;
    cin >> a >> b;
    ll even0 = 0, odd0 = 0, even1 = 0, odd1 = 0;
    FOR (i, 0, n) {
        if (a[i] == '0') {
            if (i % 2 == 0) even0++;
            else odd0++;
        } else {
            if (i % 2 == 0) even1++;
            else odd1++;
        }
        if (b[i] == '0') {
            if (i % 2 == 1) even0++;
            else odd0++;
        } else {
            if (i % 2 == 1) even1++;
            else odd1++;
        }
    }
    if (n % 2 == 0) {
        if (even1 > even0 || odd1 > odd0) {
            cout << "NO\n";
            return;
        } else {
            cout << "YES\n";
            return;
        }
    } else {
        if (even1 > even0) {
            cout << "NO\n";
            return;
        } else if (odd1 > odd0 + 1) {
            cout << "NO\n";
            return;
        } else {
            cout << "YES\n";
            return;
        }
    }
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
#ifdef GOOGLE
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
#endif
}
