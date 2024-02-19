#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, a, b, c;
vector<int> flow;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        flow.push_back(a);
    }
    while (true) {
        cin >> a;
        if (a == 99) {
            cin >> b >> c;
            flow.insert(flow.begin() + b, flow[b - 1] - (int) (c * 0.01 * flow[b - 1]));
            flow[b - 1] = (int) c * 0.01 * flow[b - 1];
        } else if (a == 88) {
            cin >> b;
            flow[b - 1] += flow[b];
            flow.erase(flow.begin() + b);
        } else {
            break;
        }
    }
    for (int i = 0; i < flow.size(); ++i) {
            cout << flow[i] << " ";
        }
        cout << "\n";
    return 0;
}