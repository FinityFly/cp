#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
/*

*/
int n;
string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    if (s == "left") {
        if (n % 2 == 0)
            cout << "right\n";
        else
            cout << "left\n";
    } else {
        if (n % 2 == 0)
            cout << "left\n";
        else 
            cout << "right\n";
    }
    return 0;
}