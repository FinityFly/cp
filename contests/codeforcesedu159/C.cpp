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

ll n;
ll a[200001];

void solve() {
    fill(a, a+200001, 0);
    cin >> n;
    ll minE = LLONG_MAX, maxE = LLONG_MIN;
    FOR (i, 0, n) {
        cin >> a[i];
        minE = min(minE, a[i]);
    }
    if (minE < 0) {
        FOR (i, 0, n) {
            a[i] += minE * -1;
            maxE = max(maxE, a[i]);
        }
    } else {
        FOR (i, 0, n) {
            a[i] -= minE;
            maxE = max(maxE, a[i]);
        }
    }
    ll minOps = LLONG_MAX, multiple=1;
    FOR (i, 1, maxE) {
        ll ops=0;
        FOR (j, 0, n) {
            if (a[j] == maxE) continue;
            if ((maxE-a[j]) % i != 0) {
                ops = LLONG_MAX;
                break;
            } else {
                ops += (maxE-a[j]) / i;
            }
            // cout << ops << " ";
        }
        // cout << "\n";
        if (ops < minOps) {
            minOps = ops;
            multiple = i;
        }
    }
    if (minOps == LLONG_MAX) minOps = 0;
    bool found = false;
    for (ll i = maxE-multiple; i >= -multiple; i-=multiple) {
        if (find(begin(a), end(a), i) == end(a)) {
            minOps += (maxE-i)/multiple;
            found = true;
            break;
        }
    }
    if (!found) {
        minOps += n * multiple;
    }
    cout << minOps << "\n";
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
