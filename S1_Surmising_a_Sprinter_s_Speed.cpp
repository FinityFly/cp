#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    pair<int, int> data[n];
    for (int i=0;i<n;++i) {
        cin >> a >> b;
        data[i].first = a;
        data[i].second = b;
    }
    sort(data, data+n);
    double max=0;
    for (int i=0;i<n-1;++i) {
         if (abs(data[i+1].second-data[i].second)/(data[i+1].first-data[i].first) > max) {
            max = (double) abs(data[i+1].second-data[i].second)/ (double) (data[i+1].first-data[i].first);
        }
    }
    std::cout << fixed << setprecision(1) << max;
    return 0;
}