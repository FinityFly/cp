#include <bits/stdc++.h>

using namespace std;
#define PB push_back
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    int n, a, b, minx=99, miny=99, maxx=0, maxy=0;
    int n, a, b, index, minx=99, miny=99, maxx=0, maxy=0;
    string temp;
    cin >> n;
    while(n--){
//        scanf("%d,%d", &a, &b);
        cin >> temp;
        index = temp.find(',');
        b = stoi(temp.substr(index+1, temp.size()-(index+1)));
        a = stoi(temp.substr(0, index));
        if(a < minx)
            minx = a;
        if(b < miny)
            miny = b;
        if(a > maxx)
            maxx = a;
        if(b > maxy)
            maxy = b;
    }
    cout << "\n" << minx-1 << "," << miny-1 << "\n" << maxx+1 << "," << maxy+1;
    return 0;
}