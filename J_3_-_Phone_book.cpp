#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, d, maxcnt=-1;
string maxn;
map<string, string> names;
map<string, int> freq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        names[b] = a;
    }
    cin >> d;
    for (int i = 0; i < d; ++i) {
        string a;
        cin >> a;
        ++freq[a];
        if ((freq[a] == maxcnt && a < maxn) || freq[a] > maxcnt) {
            maxcnt = freq[a];
            maxn = a;
        }
    }
    cout << names[maxn] << "\n";
    return 0;
}