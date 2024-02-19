#include <bits/stdc++.h>
using namespace std;

/*

*/

void print_grid(int grid[100][100]) {
    for (int i = 0; i < 100; ++i) {
        bool hasContent = false;
        for (int j = 0; j < 100; ++j) {
            if (grid[i][j] != 0) {
                cout << grid[i][j] << " ";
                hasContent = true;
            }
        }
        if (hasContent)
            cout << "\n";
    }
}

// void print_grid(int grid[10][10]) {
//     for (int i = 0; i < 10; ++i) {
//         for (int j = 0; j < 10; ++j) {
//             cout << grid[i][j] << " ";
//         }
//         cout << "\n";
//     }
//     cout << "\n";
// }

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> a >> b;
    int cur_size = 2;
    int cur_key = 4;
    int output[100][100] = {{}};
    for (int i = a; i <= b;) {
        // top left to bottom left
        for (int j = 0; j < cur_size-1 && i <= b; ++j, ++i) {
            output[cur_key+j][cur_key] = i;
        }
        // bottom left to bottom right
        for (int j = 0; j < cur_size-1 && i <= b; ++j, ++i) {
            output[cur_key+cur_size-1][cur_key+j] = i;
        }
        // bottom right to top right
        for (int j = 0; j < cur_size && i <= b; ++j, ++i) {
            output[cur_key+cur_size-j-1][cur_key+cur_size-1] = i;
        }
        // top right to top left
        for (int j = 0; j < cur_size && i <= b; ++j, ++i) {
            output[cur_key-1][cur_key+cur_size-j-1] = i;
        }
        --cur_key;
        cur_size += 2;
    }
    print_grid(output);
    return 0;
}