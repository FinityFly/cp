#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef vector<pair<ll, ll> > vpll;

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

ll n, sum=0;

void solve() {
	cin >> n;
	if (n == 1 || n == 2) {
		cout << "NO\n";
		return;
	} else if (n == 3) {
		cout << "YES\n";
		cout << "1\n3\n2\n1 2\n";
		return;
	}
	FOR (i, 1, n+1) sum += i;
	if (sum % 2 == 1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	if (n % 2 == 0) {
		cout << n/2 << "\n";
		for (int i = 1; i <= n/2; i += 2) {
			cout << i << " " << n-i+1 << " ";
		}
		cout << "\n" << n/2 << "\n";
		for (int i = 2; i <= n/2; i += 2) {
			cout << i << " " << n-i+1 << " ";
		}
	} else if (n >= 7) {
		cout << n/2+1 << "\n1 2 ";
		for (int i = 4; i <= (n+3)/2; i += 2) {
			cout << i << " " << n-i+4 << " ";
		}
		cout << "\n" << n/2 << "\n3 ";
		for (int i = 5; i <= (n+3)/2; i += 2) {
			cout << i << " " << n-i+4 << " ";
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
