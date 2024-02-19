#include <bits/stdc++.h>
using namespace std;

/*
INPUT:
7 10
4 8
 */

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    ifstream fin("paint.in");
    ofstream fout("paint.out");
    int a, b, c, d, l, r;
    fin >> a >> b >> c >> d;
    if(a < b && b < c && c < d || c < d && d < a && a < b)
        fout << b-a + d-c << "\n";
    else {
        l = (a < c) ? a : c;
        r = (b > d) ? b : d;
        fout << r - l << "\n";
    }
    return 0;
}