#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, square = 1;
    map<int, int> snakes = {{54, 19}, {90, 48}, {99, 77}}, ladders = {{9, 34}, {40, 64}, {67, 86}};
    while (true) {
        cin >> n;
        if (n == 0) {
            cout << "You Quit!" << "\n";
            break;
        }
        if (square + n <= 100) {
            square += n; 
            if (snakes.find(square) != snakes.end()) {
                square = snakes[square];
            } else if (ladders.find(square) != ladders.end()) {
                square = ladders[square];
            }
            cout << "You are now on square " << square << "\n";
            if (square >= 100) {
                cout << "You Win!" << "\n";
                break;
            }
        } else {
            cout << "You are now on square " << square << "\n";
        }
        
    }
    
    return 0;
}