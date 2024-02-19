#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*
INPUT:



1>2>3>1
1>3>2>1
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y, a=0, b=0;
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    fin >> n;
    for(int i=0;i<n;++i){
        fin >> x >> y;
        if((x == 1 && y == 3) || (x == 2 && y == 1) || (x == 3 && y == 2)) {
            a++;
        } else if((x == 1 && y == 2) || (x == 2 && y == 3) || (x == 3 && y == 1)) {
            b++;
        }
    }
    fout << max(a, b) << "\n";
    return 0;
}