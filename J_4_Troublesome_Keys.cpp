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

#define SINGLE ;
// #define MULTIPLE ;
// #define GOOGLE ;

string s1, s2;
char silly = ' ', displayed = ' ', quiet = '-';

void solve() {
    cin >> s1 >> s2;
    ll i = 0, j = 0;
    while (i < s1.length() && j < s2.length()) {
        if (s1[i] != s2[j]) {
            if (s1[i] == quiet) {
                ++i;
            } else if (s1[i] == silly) {
                ++i; ++j;
            } else if (silly == ' ' && quiet != '-') {
                silly = s1[i];
                displayed = s2[j];
                break;
            } else if (silly != ' ' && quiet == '-') {
                quiet = s1[i];
                break;
            } else if (silly == ' ' && quiet == '-') {
                if (i >= s1.length() - 1) {
                    silly = s1[i];
                    displayed = s2[j];
                    break;
                }
                // figure out if quiet
                int next = i;
                while (next < s1.length() && s1[next] == s1[i]) next++;
                if (next == s1.length()) {
                    silly = s1[i];
                    displayed = s2[j];
                    break;
                }
                if (s1[next] == s2[j]) {
                    quiet = s1[i];
                    i = next;
                } else {
                    silly = s1[i];
                    displayed = s2[j];
                    i = next; j = next;
                }
            }
        } else {
            ++i; ++j;
        }
    }
    if (i < s1.length() && j >= s2.length()) quiet = s1[i];
    cout << silly << " " << displayed << "\n" << quiet << "\n";
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
    freopen("./j4/j4.04.09.in", "r", stdin);
    // freopen("./j4/j4.sample.01.out", "w", stdout);
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
