#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string n;
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    while (true) {
        cin >> n;
        if (n == "quit!") {
            break;
        }
        if (n.length() > 4) {
            while (true) {
                if (n.substr(n.length()-2, n.length()-1) == "or" && find(begin(vowels), end(vowels), n.at(n.length()-3)) == end(vowels)) {
                    n = n.substr(0, n.length()-2) + "our";
                } else {
                    break;
                }
            }
        }
        cout << n << "\n";
    }
    
    return 0;
}