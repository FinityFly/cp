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

ll n;

void solve() {
	cin >> n;
	FOR (i, 0, n) {
		map<string, ll> freq;
		vector<string> getString[1001];
		vll cnt;
		ll m, k; cin >> m >> k;
		FOR (j, 0, m) {
			string s; cin >> s;
			freq[s]++;
		}
		TRAV (j, freq) {
			getString[j.second].push_back(j.first);
			if (find(cnt.begin(), cnt.end(), j.second) == cnt.end())
				cnt.push_back(j.second);
		}
		sort(cnt.begin(), cnt.end(), greater<ll>());
		//FOR (j, 0, cnt.size()) {
			//cout << cnt[j] << ": ";
			//TRAV (w, getString[cnt[j]]) {
				//cout << w << " ";
			//}
			//cout << "\n";
		//}
		//cout << "\n";
		string suffix = "th";
		if (k % 10 == 1 && k % 100 != 11) suffix = "st";
		else if (k % 10 == 2 && k % 100 != 12) suffix = "nd";
		else if (k % 10 == 3 && k % 100 != 13) suffix = "rd";
		cout << k << suffix << " most common word(s):\n";
		FOR (j, 0, cnt.size()) { 
			//cout << k << "\n";
			if (k > 1) {
				k -= getString[cnt[j]].size();
			} else if (k == 1) {
				TRAV (w, getString[cnt[j]]) {
					cout << w << "\n";
				}
				break;
			} else break;
		}
		cout << "\n";
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
