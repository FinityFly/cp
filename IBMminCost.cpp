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

int n, m, k;
vector<vector<int> > plans;

bool op (const vector<int> a, const vector<int> b) {
    return a[3] < b[3];
}

ll getMinCost() {
    int minCost = 0;
    sort(plans.begin(), plans.end(), op);
    for (int i = 1; i <= n; ++i) {
        ll cnt=0, ind=0, cost=0;
        while (cnt < k && ind < m) {
            // cout << plans[ind][0] << " " << plans[ind][1] << " " << plans[ind][2] << " " << plans[ind][3] << "\n";
            if (i >= plans[ind][0] && i <= plans[ind][1]) {
                if (cnt + plans[ind][2] >= k) {
                    cost += (k - cnt) * plans[ind][3];
                    cnt = k;
                } else {
                    cost += plans[ind][2] * plans[ind][3];
                    cnt += plans[ind][2];
                }
            }
            // cout << "cost: " << cost << "\n";
            ind++;
        }
        minCost += cost;
        // cout << "minCost: " << minCost << "\n";
    }
    return minCost;
}

void solve() {
    cin >> n >> k >> m;
    FOR (i, 0, m) {
        vector<int> temp;
        FOR (j, 0, 4) {
            int t; cin >> t;
            temp.push_back(t);
        }
        plans.push_back(temp);
    }
    cout << getMinCost() << "\n";
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
