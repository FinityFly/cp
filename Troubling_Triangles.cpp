#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n;
ld s1, s2, s3, p, sp;
pair<ld, ld> coords[3];

ld area() {
    return sqrt(sp*(sp-s1)*(sp-s2)*(sp-s3));
}

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt(pow(abs(x2-x1), 2.0) + pow(abs(y2-y1), 2.0));
}

ld perimeter() {
    s1 = dist(coords[0].first, coords[0].second, coords[1].first, coords[1].second);
    s2 = dist(coords[0].first, coords[0].second, coords[2].first, coords[2].second);
    s3 = dist(coords[1].first, coords[1].second, coords[2].first, coords[2].second);
    return s1+s2+s3;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int t = 0; t < n; ++t) {
        for (int i = 0; i < 3; ++i) {
            ld x, y;
            cin >> x >> y;
            coords[i] = {x, y};
        }
        p = perimeter();
        sp = p/2;
        cout << fixed << setprecision(9) << area() << " " << p << "\n";
    }
    return 0;
}