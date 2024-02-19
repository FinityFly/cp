#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("square.in");
    ofstream fout("square.out");
    int x1, y1, x2, y2, x3, y3, x4, y4, maxx, maxy, maxlen, temp;
    fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    maxx = (abs(x1 - x4) > abs(x2 - x3)) ? abs(x1 - x4) : abs(x2 - x3);
    temp = (abs(x2 - x1) > abs(x4 - x3)) ? abs(x2 - x1) : abs(x4 - x3);
    maxx = (temp > maxx) ? temp : maxx;
    maxy = (abs(y1 - y4) > abs(y2 - y3)) ? abs(y1 - y4) : abs(y2 - y3);
    temp = (abs(y2 - y1) > abs(y4 - y3)) ? abs(y2 - y1) : abs(y4 - y3);
    maxy = (temp > maxy) ? temp : maxy;
    maxlen = (maxx > maxy) ? maxx : maxy;
    fout << pow(maxlen, 2) << "\n";

    return 0;
}