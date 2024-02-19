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

ll n, c;
bool comb[9];

ll getType(ll a) {
    if (a % 2 == 0) {
        if (a % 3 != 1) return 1;
        else return 2;
    } else {
        if (a % 3 != 1) return 3;
        else return 4;
    }
}

void on(int type) {
    if (type == 1) {
        comb[3]=0;
        comb[4]=0;
        comb[7]=0;
        comb[8]=0;
    } else if (type == 2) {
        comb[3]=0;
        comb[4]=0;
        comb[5]=0;
        comb[6]=0;
    } else if (type == 3) {
        comb[2]=0;
        comb[4]=0;
        comb[6]=0;
        comb[8]=0;
    } else if (type == 4) {
        comb[2]=0;
        comb[4]=0;
        comb[5]=0;
        comb[7]=0;
    }
}

void off(int type) {
    if (type == 1) {
        comb[1]=0;
        comb[2]=0;
        comb[5]=0;
        comb[6]=0;
    } else if (type == 2) {
        comb[1]=0;
        comb[2]=0;
        comb[7]=0;
        comb[8]=0;
    } else if (type == 3) {
        comb[1]=0;
        comb[3]=0;
        comb[5]=0;
        comb[7]=0;
    } else if (type == 4) {
        comb[1]=0;
        comb[3]=0;
        comb[6]=0;
        comb[8]=0;
    }
}

void solve() {
    fill(comb, comb+9, 1);
    cin >> n >> c;
    if (c == 1) {
        comb[1] = 0;
        comb[6] = 0;
        comb[7] = 0;
        comb[8] = 0;
    } else if (c == 2) {
        comb[5] = 0;
    }
    ll a; cin >> a;
    while (a != -1) {
        on(getType(a));
        cin >> a;
    }
    cin >> a;
    while (a != -1) {
        off(getType(a));
        cin >> a;
    }
    ll combs[9][5] = { {0, 0, 0, 0, 0}, 
                       {0, 1, 1, 1, 1},
                       {0, 1, 1, 0, 0},
                       {0, 0, 0, 1, 1},
                       {0, 0, 0, 0, 0},
                       {0, 1, 0, 1, 0},
                       {0, 1, 0, 0, 1},
                       {0, 0, 1, 1, 0},
                       {0, 0, 1, 0, 1} };

    FOR (i, 1, 9) {
        if (comb[i]) {
            FOR (j, 1, n+1) {
                ll t = getType(j);
                cout << combs[i][getType(t)];
            }
            cout << "\n";
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