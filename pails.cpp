#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*
INPUT:

 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    int x, y, m, xcount=0, size, max=0;
    fin >> x >> y >> m;
    while(true){
        size = xcount*x;
        while(true){
            if(size > m)
                break;
            if(size > max)
                max = size;
            size += y;
        }
        xcount++;
        if(xcount*x > m)
            break;
    }
    fout << max << "\n";
    return 0;
}