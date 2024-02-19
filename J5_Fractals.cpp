#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*

 */
int l, w, x;
int graph[1005][1005];

int fractal(int depth) {
    fractal(depth-1);
    return 0;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> l >> w >> x;
    fractal(l);
    return 0;
}