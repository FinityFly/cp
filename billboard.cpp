#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*
INPUT:

 */

struct Rect{
    int x1, y1, x2, y2;
};

int getArea(Rect x){
    return (x.x2-x.x1)*(x.y2-x.y1);
}

int overlapArea(Rect a, Rect b){
    int xoverlap=max(0,min(a.x2,b.x2) - max(a.x1,b.x1));
    int yoverlap=max(0,min(a.y2,b.y2) - max(a.y1,b.y1));
    return xoverlap*yoverlap;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    Rect a, b, c;
    fin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2 >> c.x1 >> c.y1 >> c.x2 >> c.y2;
    fout << getArea(a) + getArea(b) - overlapArea(a, c) - overlapArea(b, c) << "\n";
    return 0;
}