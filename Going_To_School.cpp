#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
ll n, d, cnt=0, pos=0, a=1;
map<ll, pair<ll, ll>> lights;

void isGreen(ll s, ll r, ll g) {
    a = floor(s/(r+g))+1;
    if (s < a*(r+g)-g || s >= a*(r+g)) {
        cnt += abs((a*(r+g)-g) - s);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> d;
    for (ll i = 0; i < n; ++i) {
        ll p, r, g;
        cin >> p >> r >> g;
        lights[p] = {r, g};
    }
    for (auto i : lights) {
        cnt += i.first-pos;
        pos = i.first;
        isGreen(cnt, i.second.first, i.second.second);
    }
    cout << cnt+(d-pos) << "\n";
    return 0;
}