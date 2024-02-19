#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");
    int c[3], m[3];
    for (int i = 0; i < 3; ++i) {
        fin >> c[i] >> m[i];
    }
    for (int i = 0; i < 2; ++i) {
        m[i+1] = m[i] + m[i+1];
        if (m[i+1] > c[i+1]) {
            m[i] = m[i+1] - c[i+1];
            m[i+1] -= m[i];
        } else {
            m[i] = 0;
        }
    }
    m[0] = m[2] + m[0];
    if (m[0] > c[0]) {
        m[2] = m[0] - c[0];
        m[0] -= m[2];
    } else {
        m[2] = 0;
    }
    m[1] = m[0] + m[1];
    if (m[1] > c[1]) {
        m[0] = m[1] - c[1];
        m[1] -= m[0];
    } else {
        m[0] = 0;
    }
    for (int i = 0; i < 3; ++i) {
        fout << m[i] << '\n';
    }
    return 0;
}