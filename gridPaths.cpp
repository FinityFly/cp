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

char p[49];
bool visited[9][9];

ll numPaths(ll x, ll y, ll ind) {
	if (x == 7 && y == 1) return ind == 48;
	if (ind == 48) return 0;
	if (visited[x][y]) return 0;
	if (visited[x+1][y] && visited[x-1][y] && visited[x][y-1] == false && visited[x][y+1] == false && x+1 <= 6 && y-1 >= 0 && y+1 <= 6) {
		return 0;
	}
	if (visited[x][y+1] && visited[x][y-1] && visited[x-1][y] == false && visited[x+1][y] == false && y+1 <= 6 && x-1 >= 0 && x+1 <= 6) {
		return 0;
	}
	visited[x][y] = true;
	ll ans = 0;
	if (p[ind] != '?') {
		if (p[ind] == 'U' && !visited[x-1][y]) {
			ans += numPaths(x-1, y, ind+1);
		} else if (p[ind] == 'L' && !visited[x][y-1]) {
			ans += numPaths(x, y-1, ind+1);
		} else if (p[ind] == 'D' && !visited[x+1][y]) {
			ans += numPaths(x+1, y, ind+1);
		} else if (p[ind] == 'R' && !visited[x][y+1]) {
			ans += numPaths(x, y+1, ind+1);
		}
	} else if ((y > 2) && visited[x][y-2] && (visited[x-1][y-1] || visited[x+1][y-1]) && !visited[x][y-1]) {
		ans += numPaths(x, y-1, ind+1);
	} else if ((y < 6) && visited[x][y+2] && (visited[x-1][y+1] || visited[x+1][y+1]) && !visited[x][y+1]) {
		ans += numPaths(x, y+1, ind+1);
	} else if ((x > 2) && visited[x-2][y] && visited[x-1][y-1] && !visited[x-1][y]) {
		ans += numPaths(x-1, y, ind+1);
	} else {
		if (!visited[x-1][y]) ans += numPaths(x-1, y, ind+1);
		if (!visited[x][y-1]) ans += numPaths(x, y-1, ind+1);
		if (!visited[x+1][y]) ans += numPaths(x+1, y, ind+1);
		if (!visited[x][y+1]) ans += numPaths(x, y+1, ind+1);
	} 
	visited[x][y] = false;
	return ans;
}

void solve() {
	FOR (i, 0, 48) {
		cin >> p[i];
	}
	FOR (i, 0, 9) {
		visited[0][i] = visited[i][0] = true;
		visited[8][i] = visited[i][8] = true;
	}
	cout << numPaths(1, 1, 0) << "\n";
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
