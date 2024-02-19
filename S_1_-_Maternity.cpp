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
string m, f;
bool canLower[5], canUpper[5];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> f >> n;
    fill(canLower, canLower+5, true);
    fill(canUpper, canUpper+5, true);
    for (int i = 0; i < 5; ++i) {
        if ((isupper(m[i*2]) && isupper(m[i*2+1])) || (isupper(f[i*2]) && isupper(f[i*2+1]))) {
            canLower[i] = false;
        } else if (islower(m[i*2]) && islower(m[i*2+1]) && islower(f[i*2]) && islower(f[i*2+1])) {
            canUpper[i] = false;
        }
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        bool isBaby = true;
        for (int j = 0; j < 5; ++j) {
            if ((!canLower[j] && islower(s[j])) || (!canUpper[j] && isupper(s[j]))) {
                isBaby = false;
                break;
            }
        }
        if (isBaby)
            cout << "Possible baby.\n";
        else
            cout << "Not their baby!\n";
    }
    return 0;
}