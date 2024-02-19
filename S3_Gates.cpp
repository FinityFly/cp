#include <bits/stdc++.h>
using namespace std;

/*
INPUT:

 */

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int g, p, count=0;
    cin >> g >> p;
    vector<bool> gate(g+1);
    for (int i=0;i<p;++i) {
        int a;
        cin >> a;
        bool isPossible = false;
        for (int j=a;j>=1;--j) {
            if (gate[j] == false) {
                gate[j] = true;
                isPossible = true;
                break;
            }
        }
        if (isPossible) {
            ++count;
        } else {
            break;
        }
    }
    cout << count;
    return 0;
}