#include <bits/stdc++.h>
using namespace std;

/*
INPUT:
3 10 8 2
 */

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");
    int a, b, x, y, n, m, ans;
    fin >> a >> b >> x >> y;
    n = (abs(a-x) < abs(a-y)) ? abs(a-x) : abs(a-y);
    m = (abs(b-y) < abs(b-x)) ? abs(b-y) : abs(b-x);
    ans = (n+m < abs(a-b)) ? n+m : abs(a-b);
    fout << ans << "\n";
    return 0;
}