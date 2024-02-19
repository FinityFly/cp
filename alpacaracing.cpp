#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K, X;
    long long D, P;
    cin >> N >> D >> K >> X;
    vector<long long> speed(N);
    for(int i = 0; i < N; i++) {
        cin >> speed[i];
    }
    cin >> P;
    int deviceUsed = 0;
    for(int i = 0; i < N; ++i) {
        while(P <= speed[i]) {
            speed[i] = speed[i] * (100 - X) / 100;
            deviceUsed++;
        }
        if (K - deviceUsed < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (K - deviceUsed >= 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}