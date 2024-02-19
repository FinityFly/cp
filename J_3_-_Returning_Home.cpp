#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n=0;
string streets[6];
char turns[6];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (cin >> turns[n] >> streets[n+1]) {
        if (streets[n] == "SCHOOL") break;
        ++n;
    }
    for (int i = n-1; i >= 0; --i) {
        if (i == 0) {
            if (turns[i] == 'R') {
                cout << "Turn LEFT into your HOME.\n";
            } else {
                cout << "Turn RIGHT into your HOME.\n";
            }
        } else if (turns[i] == 'R') {
            cout << "Turn LEFT onto " << streets[i] << " street.\n";
        } else {
            cout << "Turn RIGHT onto " << streets[i] << " street.\n";
        }
    }
    return 0;
}