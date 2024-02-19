#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, hp=50, cnt=0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        hp += a;
        if (hp <= 0) {
            ++cnt;
            hp = 10;
        } else if (hp > 50) hp = 50;
    }
    cout << cnt;
    return 0;
}