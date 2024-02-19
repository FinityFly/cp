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

ll n, cnt=0;
vpll s;

void solve() {
	cin >> n;
	FOR (i, 0, n) {
		ll x, y; cin >> x >> y;
		s.push_back({y, x});
	}
	FOR (i, 0, n-1) {
		pll maxslope = {s[i+1].first-s[i].first, s[i+1].second-s[i].second}, minslope = {s[i+1].first-s[i].first, s[i+1].second-s[i].second};
		cnt++;
		FOR (j, i+2, n) {
			//cout << s[i].second << " " << s[i].first << " " << s[j].second << " " << s[j].first << "\n";
			if ((s[j].first - s[i].first) * maxslope.second >= (s[j].second - s[i].second) * maxslope.first) {
				maxslope = {s[j].first - s[i].first, s[j].second-s[i].second};
				cnt++;
			}
			if ((s[j].first - s[i].first) * minslope.second <= (s[j].second - s[i].second) * minslope.first) {
				minslope = {s[j].first - s[i].second, s[j].second - s[i].second};
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
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
