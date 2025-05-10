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

void solve() {
    string s;
    cin >> n;
    cin >> s;
    ll lcnt = 0, icnt = 0, tcnt = 0;
    FOR(i, 0, n) {
        if (s[i] == 'L') lcnt++;
        else if (s[i] == 'I') icnt++;
        else if (s[i] == 'T') tcnt++;
    }
    if (lcnt == icnt && lcnt == tcnt) {
        cout << "0\n";
        return;
    }
    ll target = max(lcnt, max(icnt, tcnt));
    int ind = 0;
    vll moves;
    while (ind < s.size()-1) {
        bool inserts = false;
        if ((lcnt < target) && ((s[ind] == 'I' && s[ind+1] == 'T') || (s[ind] == 'T' && s[ind+1] == 'I'))) {
            lcnt++;
            s.insert(s.begin() + ind + 1, 'L');
            moves.push_back(ind + 1);
            ind = 0;
            inserts = true;
        }
        if ((icnt < target) && ((s[ind] == 'L' && s[ind+1] == 'T') || (s[ind] == 'T' && s[ind+1] == 'L'))) {
            icnt++;
            s.insert(s.begin() + ind + 1, 'I');
            moves.push_back(ind + 1);
            ind = 0;
            inserts = true;
        }
        if ((tcnt < target) && ((s[ind] == 'L' && s[ind+1] == 'I') || (s[ind] == 'I' && s[ind+1] == 'L'))) {
            tcnt++;
            s.insert(s.begin() + ind + 1, 'T');
            moves.push_back(ind + 1);
            ind = 0;
            inserts = true;
        }
        if (lcnt == target && icnt == target && tcnt == target) {
            break;
        }
        if (!inserts) ind++;
    }
    if (lcnt == target && icnt == target && tcnt == target) {
        cout << moves.size() << "\n";
        FOR(i, 0, moves.size()) {
            cout << moves[i] << "\n";
        }
    } else {
        cout << "-1\n";
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
