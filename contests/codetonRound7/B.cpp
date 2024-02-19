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

ll t, n;
bool a[200001];
string s;

void solve() {
    cin >> t;
	FOR (i, 0, t) {
		fill(a, a+200001, false);
		cin >> n >> s;
		ll cnt = 0, swaps;
		do {
			swaps = 0;
			FOR (j, 0, n-1) {
				if (s[j] == 'A' && s[j+1] == 'B' && !a[j]) {
                    RFOR (k, j, 0) {
                        if (s[k] == 'B' || a[k]) {
                            swap(s[k], s[j]);
                            cnt += j - 1 - k; swaps += j - 1 - k;
                            break;
                        } else if (k == 0 && s[k] == 'A') {
                            swap(s[k], s[j]);
                            cnt += j - 1 - k; swaps += j - 1 - k;
                            break;
                        } else if (s[k] == 'A'){
                            a[k] = true;
                        }
                    }
                    cout << j << " " << s << " " << cnt << "\n";
                    FOR (k, 0, n) cout << a[k] << " ";
                    cout << "\n";
				}
			}
		} while (swaps > 0);
		cout << cnt << "\n";
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
