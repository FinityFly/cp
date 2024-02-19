#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n;
double d, mdist=-1;
vector<pair<int, int>> c, m;

pair<double, double> circumcentre(double ax, double ay, double bx, double by, double cx, double cy) {
    double dis = 2 * (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
    double ux = ((ax * ax + ay * ay) * (by - cy) + (bx * bx + by * by) * (cy - ay) + (cx * cx + cy * cy) * (ay - by)) / dis;
    double uy = ((ax * ax + ay * ay) * (cx - bx) + (bx * bx + by * by) * (ax - cx) + (cx * cx + cy * cy) * (bx - ax)) / dis;
    return {ux, uy};
}

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(abs(x2-x1), 2.0) + pow(abs(y2-y1), 2.0));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p, q;
        cin >> p >> q;
        c.push_back({p, q});
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            d = dist(c[i].first, c[i].second, c[j].first, c[j].second);
            if (d > mdist) {
                mdist = d;
                m = {c[i], c[j]};
            }
        }
    }
    for (auto i : c) {
        if ((i.first != m[0].first || i.second != m[0].second) && (i.first != m[1].first || i.second != m[1].second)) {
            if (dist(i.first, i.second, (m[0].first+m[1].first)/2, (m[0].second+m[1].second)/2)*2 > mdist) {
                pair<double, double> cc = circumcentre(m[0].first, m[0].second, m[1].first, m[1].second, i.first, i.second);
                mdist = max(mdist, 2.0 * dist(cc.first, cc.second, i.first, i.second));
            }
        }
    }
    cout << fixed << setprecision(2) << mdist << "\n";
    return 0;
}