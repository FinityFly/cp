#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");
    vector< pair<int, int> > road;
    int n, m, rdist=0, bdist=0, rindex=0, max=-1;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        road.push_back(make_pair(a, b));
    }
    for (int i = 0; i < m; ++i) {
        int d, v;
        cin >> d >> v;
        while (rdist <= bdist) {
            rdist += road[rindex].first;
            if (road[rindex].second - v > max) {
                max = road[rindex].second - v;
            }
            ++rindex;
        }
        --rindex;
        road[rindex].first -= d;
        bdist += d;
    }
    cout << max << "\n";
    return 0;
}