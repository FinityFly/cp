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

ll n, m;
ll a[500001], dist[500001];
vll adj[500001];

ll dijk(ll root, ll target) {
	ll ind=0, mindist=1e18;
	fill(dist, dist+500001, LLONG_MAX);
	priority_queue<pll, vpll, greater<pll>> pq;
	pq.push({root, 0});
	dist[root] = 0;
	while (!pq.empty()) {
		pll u = pq.top(); pq.pop();
		if (a[u.first] == target && u.second < mindist) {
			mindist = u.second;
			ind = u.first;
			continue;
		}
		TRAV (v, adj[u.first]) {
			if (dist[v] > u.second + abs(u.first-v)) {
				dist[v] = u.second + abs(u.first-v);
				pq.push({v, u.second + abs(u.first-v)});
			}
		}
	}
	return dist[ind];
}


void solve() {
	cin >> n >> m;
	a[0] = 0;
	n++;
	FOR (i, 1, n) {
		cin >> a[i];
	}
	FOR (i, 0, n) {
		bool fl = false, fr = false;
		FOR (j, 1, n) {
			if (i+j < n && !fr) {
				if (a[i+j] - a[i] == 1) {
					adj[i].push_back(i+j);
					fr = true;
				}
			}
			if (i-j >= 1 && !fl) {
				if (a[i-j] - a[i] == 1) {
					adj[i].push_back(i-j);
					fl = true;
				}
			}
			if (fl && fr) break;
		}
	}
	cout << dijk(0, m) << "\n";
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
