#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, miny=INT_MAX, mincnt=0;
vector<pair<int, int>> minsheep;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ld x, y;
        cin >> x >> y;
        if (y*1000 < miny) {
            miny = y*1000;
            mincnt = 1;
            minsheep.clear();
            minsheep.push_back({x*1000, y*1000});
        } else if (y*1000 == miny) {
            ++mincnt;
            minsheep.push_back({x*1000, y*1000});
        }
    }
    for (int i = 0; i < mincnt; ++i) {
        cout << fixed << setprecision(2) << "The sheep at (" << (double) minsheep[i].first / 1000  << ", " << (double) minsheep[i].second / 1000 << ") might be eaten.\n";
    }
    return 0;
}