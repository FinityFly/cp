#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, curn=0;
int a[100001];
vector<pii> p;

bool exists(int curn) {
    for (int i = 0; i < p.size(); ++i) {
        if (p[i].first == curn) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == curn + 1) {
            curn = a[i];
        } else if (a[i] <= curn && !exists(a[i])) {
            p.push_back({a[i], i});
        }
    }
    sort(p.begin(), p.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.first > rhs.first;
    });
    for (int i = 0; i < p.size(); ++i) {
        int l=p[i].first;
        bool isPossible = false;
        for (int j = p[i].second+1; j < n; ++j) {
            if (l-1 == a[j]) {
                l = a[j];
            }
            if (l == 1) {
                isPossible = true;
                break;
            } else if (j == n-1) {
                break;
            }
        }
        if (isPossible) {
            cout << p[i].first << "\n";
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}