#include <bits/stdc++.h>

using namespace std;
#define PB push_back
typedef long long ll;

int m, n, o, p;
int grid[1005][1005];
bool isPossible = false;

void solve(int r, int c){
    if(!isPossible) {
        vector<pair<int, int> > instances;
        cout << "solve: r=" << r << ", c=" << c << " - p=" << r * c << "\n";
        if (r == 1 && c == 1) {
            isPossible = true;
            return;
        }
        if (grid[r-1][c-1] != r*c) {
            p = r * c;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == p) {
                        instances.push_back(make_pair(i, j));
                        cout << "pair: " << i + 1 << ", " << j + 1 << "\n";
                    }
                }
            }
            o = instances.size();
            for (int i = 0; i < o; ++i) {
                cout << instances[i].first + 1 << "," << instances[i].second + 1 << "\n";
                solve(instances[i].first + 1, instances[i].second + 1);
            }
        } else {
            cout << "log 1\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << "Ready\n";
    cin >> m >> n;
    int temp;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin >> temp;
            grid[i][j] = temp;
        }
    }
    solve(m, n);
    if(isPossible)
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}

//#include <bits/stdc++.h>
//
//using namespace std;
//#define PB push_back
//typedef long long ll;
//
//int m, n, o, p;
//int grid[1005][1005];
//bool isPossible = false;
//
//void solve(int r, int c){
//    if(!isPossible) {
//        cout << "solve: r=" << r << ", c=" << c << " - p=" << r * c << "\n";
//        if (r == 1 && c == 1) {
//            isPossible = true;
//            return;
//        }
//        if (grid[r][c] != r * c)
//            p = r * c;
//        else
//            return;
//        for (int i=0;i<m;++i) {
//            for (int j=0;j<n;++j) {
//                if (grid[i][j] == p) {
//                    cout << "pair: " << i + 1 << ", " << j + 1 << "\n";
//                    solve(i + 1, j + 1);
//                }
//            }
//        }
//    }
//}
//
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout << "Ready\n";
//    cin >> m >> n;
//    int temp;
//    for(int i=0;i<m;++i){
//        for(int j=0;j<n;++j){
//            cin >> temp;
//            grid[i][j] = temp;
//        }
//    }
//    solve(m, n);
//    if(isPossible)
//        cout << "yes\n";
//    else
//        cout << "no\n";
//    return 0;
//}