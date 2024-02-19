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

ll n, m;
ll arr[100001], bsum[100001], bfreq[100001];

void updateSum(ll ind, ll change) {
    while (ind <= n) {
        bsum[ind] += change;
        ind += ind& - ind;
    }
}

void freqIncrease(ll val) {
    while (val <= 100000) {
        bfreq[val]++;
        val += val& - val;
    }
}

void freqDecrease(ll val) {
    while (val <= 100000) {
        bfreq[val]--;
        val += val& - val;
    }
}

ll prefixSum(ll ind) {
    ll sum=0;
    while (ind >= 1) {
        sum += bsum[ind];
        ind -= ind& - ind;
    }
    return sum;
}

ll prefixFreq(ll val) {
    ll freq=0;
    while (val >= 1) {
        freq += bfreq[val];
        val -= val& - val;
    }
    return freq;
}

void solve() {
    cin >> n >> m;
    FOR (i, 1, n+1) {
        cin >> arr[i];
        updateSum(i, arr[i]);
        freqIncrease(arr[i]);
    }
    FOR (i, 0, m) {
        char q; cin >> q;
        if (q == 'C') {
            ll x, v; cin >> x >> v;
            updateSum(x, v-arr[x]);
            freqIncrease(v);
            freqDecrease(arr[x]);
            arr[x] = v;
        } else if (q == 'S') {
            ll l, r; cin >> l >> r;
            cout << prefixSum(r) - prefixSum(l-1) << "\n";
        } else if (q == 'Q') {
            ll v; cin >> v;
            cout << prefixFreq(v) << "\n";
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