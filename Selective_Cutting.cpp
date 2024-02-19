#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
/*

*/
int n, Q;
int psa[100002];

struct Query {
	int l, r, x, i, out;
};

bool rule1(Query q1, Query q2) {
	return q1.x > q2.x;
}

bool rule2(Query q1, Query q2) {
	return q1.i < q2.i;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<pii> mass(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        mass[i].first = i;
        mass[i].second = a;
    }
    sort(mass.rbegin(), mass.rend());
    cin >> Q;
    vector<Query> q(Q);
    for (int i = 0; i < n; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        q[i].l = l; q[i].r = r; q[i].x = x; q[i].i = i;
    }
    sort(q.begin(), q.end(), rule1);
    for (int i = 0; i < n; ++i) {
        cout << q[i].i << " " << q[i].l << " " << q[i].r << " " << q[i].x << "\n";
    }
    
    return 0;
}