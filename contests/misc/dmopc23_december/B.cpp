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

#define SINGLE ;
// #define MULTIPLE ;
// #define GOOGLE ;

ll n, k, cnt=0;
bool g[2001][2001];

void solve() {
    cin >> n;
    k = (pow(n, 2) + (3 * n)) / 5;
    for (int i = 2; i < n; i+=5) {
        cnt += n;
        fill(g[i], g[i]+n, 1);
    }
    if ((n+2) % 5 == 3) {
        g[n-4][0] = g[n-4][n-1] = 0;
        cnt -= 2;
        for (int i = 0; i < n-3; i+=4) {
            cnt += 2;
            g[n-3][i+1] = g[n-3][i+2] = 1;
        }
        if (n % 4 == 1) {
            cnt++;
            g[n-3][n-2] = 1;
        } else if (n % 4 == 2) {
            cnt += 2;
            g[n-3][n-3] = g[n-3][n-2] = 1;
        } else if (n % 4 == 3) {
            cnt += 2;
            g[n-3][n-3] = g[n-3][n-2] = 1;
        }
    } else if ((n+2) % 5 == 4) {
        g[n-5][0] = g[n-5][n-1] = 0;
        cnt -= 2;
        for (int i = 0; i < n-5; i+=6) {
            cnt += 4;
            g[n-3][i+1] = g[n-3][i+2] = g[n-3][i+3] = g[n-3][i+4] = 1;
        }
        if (n % 6 == 1) {
            cnt++;
            g[n-3][n-2] = 1;
        } else if (n % 6 == 2) {
            cnt += 2;
            g[n-3][n-3] = g[n-3][n-2] = 1;
        } else if (n % 6 == 3) {
            cnt += 3;
            g[n-3][n-4] = g[n-3][n-3] = g[n-3][n-2] = 1;
        } else if (n % 6 == 4) {
            cnt += 3;
            g[n-3][n-4] = g[n-3][n-3] = g[n-3][n-2] = 1;
        } else if (n % 6 == 5) {
            cnt += 4;
            g[n-3][n-5] = g[n-3][n-4] = g[n-3][n-3] = g[n-3][n-2] = 1;
        }
    }
    if (k < cnt) {
        cout << "-1\n";
        return;
    } else if (k > cnt) {
        FOR (i, 0, n) {
            FOR (j, 0, n) {
                if (g[i][j] == 0) {
                    g[i][j] = 1;
                    cnt++;
                }
                if (k == cnt) break;
            }
            if (k == cnt) break;
        }
    }
    if (k < cnt) {
        cout << "-1\n";
        return;
    }
    FOR (i, 0, n) {
        FOR (j, 0, n) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
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
