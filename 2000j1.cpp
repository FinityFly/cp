#include <bits/stdc++.h>
using namespace std;

/*
INPUT:

 */

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;
    cin >> a >> b;
    cout << "Sun Mon Tue Wed Thr Fri Sat\n";
    if (a > 1) {
        cout << "   ";
        for (int i=1; i<a-1; ++i) {
            cout << "    ";
        }
    }
    for (int i=1; i<b+1; ++i) {
        if ((i + (a - 2)) % 7 == 0 && to_string(i).length() == 2) {
            cout << " ";
        } else if (((i + (a - 2)) % 7 == 0 && to_string(i).length() == 1) || to_string(i).length() == 2) {
            cout << "  ";
        } else {
            cout << "   ";
        }
        cout << i;
        if ((i + (a - 1)) % 7 == 0 && i != b) {
            cout << "\n";
        }
    }
    return 0;
}
