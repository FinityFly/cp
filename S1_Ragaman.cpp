#include <bits/stdc++.h>
using namespace std;

/*
INPUT:

 */

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a, b;
    int stars=0;
    cin >> a >> b;
    for (int i=0;i<b.length();++i) {
        if (b[i] == '*') {
            ++stars;
        }
    }
    bool isAnagram = true;
    for (int i=0;i<a.length();++i) {
        if (b.find(a[i]) == b.npos) {
            cout << "not found: " << i << "\n";
            if (stars > 0) {
                cout << "star count: " << stars << "\n";
                --stars;
            } else {
                cout << "rip" << "\n";
                isAnagram = false;
                break;
            }
        } else {
            cout << "found: " << i << "\n";
            b.erase(i);
        }
        cout << "b string: " << b << "\n";
    }
    if (isAnagram) {
        cout << "A" << "\n";
    } else {
        cout << "N" << "\n";
    }
    return 0;
}