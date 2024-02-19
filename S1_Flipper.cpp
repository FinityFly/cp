#include <bits/stdc++.h>
using namespace std;

/*
INPUT:

 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int grid[4] = {1, 2, 3, 4};
    string n;
    cin >> n;
    for (int i=0;i<n.length();++i) {
        if (n.at(i) == 'H') {
            int temp = grid[0];
            grid[0] = grid[2];
            grid[2] = temp;
            temp = grid[1];
            grid[1] = grid[3];
            grid[3] = temp;
        } else {
            int temp = grid[0];
            grid[0] = grid[1];
            grid[1] = temp;
            temp = grid[2];
            grid[2] = grid[3];
            grid[3] = temp;
        }
    }
    cout << grid[0] << " " << grid[1] << "\n" << grid[2] << " " << grid[3] << "\n";
    return 0;
}