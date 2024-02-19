#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int b, n;
vector<char> p = {'A', 'B', 'C', 'D', 'E'};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (cin >> b >> n) {
        if (b == 4 && n == 1) break;
        else {
            for (int i = 0; i < n; ++i) {
                if (b == 1) {
                    p.push_back(p[0]);
                    p.erase(p.begin());
                } else if (b == 2) {
                    p.insert(p.begin(), p[4]);
                    p.pop_back();
                } else if (b == 3) {
                    p.insert(p.begin(), p[1]);
                    p.erase(p.begin()+2);
                }
            }
        }
    }
    for (int i = 0; i < p.size(); ++i) {
        cout << p[i] << " ";
    }
    return 0;
}