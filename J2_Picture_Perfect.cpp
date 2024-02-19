#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    map<int, int> snakes, ladders;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        while (true) {
            if (n % (int) floor(sqrt(n)) != 0) {
                --n;
            } else {
                cout << "Minimum perimeter is " << (floor(sqrt(n)) + n/floor(sqrt(n))) * 2 << " with dimensions " << floor(sqrt(n)) << " x " << n/floor(sqrt(n)) << "\n";
                break;
            }
        }
        
    }

    return 0;
}