#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*
INPUT:
1 2
1 1
1 1
1 2
 */

int main()
{
    ifstream fin("promote.in");
    ofstream fout("promote.out");
    int arr[4][2], a, b, c;
    for(int i=0;i<4;++i){
        for(int j=0;j<2;++j){
            fin >> arr[i][j];
        }
    }
    a = arr[3][1]-arr[3][0];
    b = arr[2][1]-arr[2][0]+a;
    c = arr[1][1]-arr[1][0]+b;
    fout << c << "\n" << b << "\n" << a << "\n";
    return 0;
}