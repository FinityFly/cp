#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*
INPUT:

 */

struct Rect{
    int x1, y1, x2, y2;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    Rect a, b;
    fin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    fin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    if(b.y2 > a.y2 && a.y1 > b.y1) {
        if(a.x2-b.x1 > 0 && a.x2-b.x2 < 0)
            a.x2 = b.x1;
        if(b.x2-a.x1 > 0 && a.x1-b.x1 > 0)
            a.x1 = b.x2;
    }
    if(b.x2 > a.x2 && a.x1 > b.x1) {
        if(a.y2-b.y1 > 0 && a.y2-b.y2 < 0)
            a.y2 = b.y1;
        if(b.y2-a.y1 > 0 && a.y1-b.y1 > 0)
            a.y1 = b.y2;
    }
    fout << (a.x2 - a.x1) * (a.y2-a.y1) << "\n";
    return 0;
}