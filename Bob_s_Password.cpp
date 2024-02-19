#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, s=INT_MAX;
string in;
char p[4];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> in;
    if (in.length() != 4) {
        cout << "weak\n";
        return 0;
    }
    for (int i = 0; i < 4; ++i) {
        p[i] = in[i];
    }
    if (p[0] == p[1] && p[1] == p[2] && p[2] == p[3]) {
        cout << "weak\n";
        return 0;
    }
    if (find(p, p+4, '0') != end(p) && find(p, p+4, '9') != end(p)) {
        if (p[0] == '0' && p[1] == '9' && p[2] == '8' && p[3] == '7') {
            cout << "weak\n";
        } else if (p[0] == '1' && p[1] == '0' && p[2] == '9' && p[3] == '8') {
            cout << "weak\n";
        } else if (p[0] == '2' && p[1] == '1' && p[2] == '0' && p[3] == '9') {
            cout << "weak\n";
        } else if (p[0] == '9' && p[1] == '0' && p[2] == '1' && p[3] == '2') {
            cout << "weak\n";
        } else if (p[0] == '8' && p[1] == '9' && p[2] == '0' && p[3] == '1') {
            cout << "weak\n";
        } else if (p[0] == '7' && p[1] == '8' && p[2] == '9' && p[3] == '0') {
            cout << "weak\n";
        } else {
            cout << "strong\n";
        }
    } else {
        if (p[0]-'0' == (p[1]-'0') - 1) { 
            for (int i = 1; i < 3; ++i) {
                if (p[i]-'0' != (p[i+1]-'0') - 1) {
                    cout << "strong\n";
                    return 0;
                }
                cout << "weak\n";
                return 0;
            }
        } else if (p[0]-'0' == (p[1]-'0') + 1) {
            for (int i = 1; i < 3; ++i) {
                if (p[i]-'0' != (p[i+1]-'0') + 1) {
                    cout << "strong\n";
                    return 0;
                }
                cout << "weak\n";
                return 0;
            }
        } else {
            cout << "strong\n";
        }
    }
    return 0;
}