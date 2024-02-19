#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e; i > (ll)s; i--)
#define TRAV(a, c) for (auto a : c)
#define all(x) x.begin(), x.end()
/*

*/

vpll adj[1001];
ll dis[1001];

void dijk(ll a) {
    priority_queue<pll, vpll, greater<pll>> pq;
    fill(dis, dis+1001, INT_MAX);
    pq.push({0, a});
    dis[a] = 0;
    while (!pq.empty()) {
        pll u = pq.top(); pq.pop();
        TRAV (v, adj[u.second]) {
            if (dis[v.first] > dis[u.second] + v.second) {
                dis[v.first] = dis[u.second] + v.second;
                pq.push({dis[v.first], v.first});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return 0;
}