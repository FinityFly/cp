#include <bits/stdc++.h>
using namespace std;

/*
INPUT:

 */

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l, r, a, b, c;
    cin >> l >> r;
    a = l%4;
    b = l%3;
    c = l%2;
    for (int i=l;i<=r;i+=5) {
        if (i%4==a && i%3==b && i%2==c) {
            cout << "All positions change in year " << i << "\n";
        }
    }
    return 0;
}