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
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define FASTIO ;
// #define PRECISION ;
// #define FILE ;

// #define SINGLE ;
#define MULTIPLE ;
// #define GOOGLE ;

ll q;

ll calculateRizz(deque<ll> b) {
    ll rizz = 0;
    for (ll i = 0; i < b.size(); ++i) {
        rizz += (i+1) * b[i];
    }
    return rizz;
}

void solve() {
    cin >> q;
    deque<ll> b;
    ll sum = 0, rizz = 0; // running calculation of outer rizz
    bool rev = false;
    while (q--) {
        ll s; cin >> s;
        if (s == 1) {
            ll tmp;
            if (rev) {
                tmp = b.front();
                b.pop_front();
                b.push_back(tmp);
            } else {
                tmp = b.back();
                b.pop_back();
                b.push_front(tmp);
            }
            rizz += sum - b.size() * tmp; // add once instance of each element, and minux the number of instances of the top element to 1
        } else if (s == 2) {
            rev = !rev;
            rizz = sum * (b.size()+1) - rizz; // max - rizz
        } else {
            ll k; cin >> k;
            sum += k;
            if (rev) {
                b.push_front(k);
            } else {
                b.push_back(k);
            }
            rizz += k * b.size();
        }
        cout << rizz << "\n";
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
