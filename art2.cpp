#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

void solve(int n, vector< pair<int> > v) 
{
    int minx=0, miny=0, maxx=100, maxy=100;
    for (int i=0;i<n;++i) {
        if(minx > v[i][0]){
            minx = v[i][0];
        }else if(maxx < v[i][0]){
            maxx = v[i][0];
        }
        if(miny > v[i][1]){
            miny = v[i][1];
        }else if(maxy < v[i][1]){
            maxy = v[i][1];
        }
    }
    // add one to each (subtract for min)
    cout << "\nminx:" << minx << "\nminy:" << miny << "\nmaxx:" << maxx << "\nmaxy:" << maxy << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector< pair<int> > values;
    vector<string> lines;
    int m;
    string a, b;
    // cin >> m;
    m = 5;
    cout << m << endl;
    while (m--){
        cin >> a;
        cout << a << endl;
        // lines.pushback
    }
    //while (cin >> x)
    for (int i=0;i<lines.size();++i)
        cout << values[i][0] << "\n";
    int n = stoi(lines[0]);
    for(int i=0;i<n;++i){
        stringstream ss(lines[i]); //might cause error cuz of reinitialize
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            values[i].push_back(stoi(substr));
        }
    }
    for (int i=0;i<n;++i)
        cout << values[i][0] << ", " << values[i][1] << "\n";
    solve(n, values);
    return 0;
}
