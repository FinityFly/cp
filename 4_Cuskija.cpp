#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e; i > (ll)s; i--)
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

#define SINGLE ;
// #define MULTIPLE ;
// #define GOOGLE ;

ll n;
vll zeroes, ones, twos;

void printDelete(vll &a) {
    cout << a[0] << " ";
    a.erase(a.begin());
}

void solve() {
    cin >> n;
    FOR (i, 0, n) {
        ll a; cin >> a;
        if (a % 3 == 0) zeroes.push_back(a);
        else if (a % 3 == 1) ones.push_back(a);
        else twos.push_back(a);
    }
    if ((zeroes.size() == 0 && ones.size() != 0 && twos.size() != 0) || ((ll)zeroes.size() - 2 >= (ll)ones.size() + (ll)twos.size())) {
        cout << "impossible\n";
        return;
    }
    ll s1 = ones.size(), s2 = twos.size();
    FOR (i, 0, s1) {
        if (zeroes.size()-1 > 0) printDelete(zeroes);
        printDelete(ones);
    }
    if (zeroes.size() > 0) printDelete(zeroes);
    FOR (i, 0, s2) {
        printDelete(twos);
        if (zeroes.size() > 0) printDelete(zeroes);
    }
    cout << "\n";
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