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

ll n, s=0, hs=0, best=INT_MAX;
ll weights[21];

ll diff(ll a, ll index) {
	if (a > s)
		return INT_MAX;
	if (index != n) {
		best = min(best, min(abs(a-hs), abs(a+weights[index]-hs)));
		if (s % 2 == 1) best = min(best, min(abs(a-hs-1), abs(a+weights[index]-hs-1)));
		//cout << a << " " << weights[index] << " " << best << "\n";
		best = min(best, diff(a+weights[index], index+1));
		best = min(best, diff(a, index+1));
		return best;
	} else {
		return abs(a-hs);
	}
}

void solve() {
	cin >> n;
	FOR (i, 0, n) {
		cin >> weights[i];
		s += weights[i];
	}
	hs = s / 2;
	//cout << s << " " << hs << "\n\n";
	diff(0, 0);
	if (s % 2 == 0)
		cout << best*2 << "\n";
	else
		cout << best*2 + 1 << "\n";
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
