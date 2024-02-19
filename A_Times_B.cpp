#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define _USE_MATH_DEFINES
typedef complex<double> cd;
#include <cmath>
const double pi = 3.141592653589;
/*

*/
string sa, sb;
vector<cd> a, b;
vector<cd> ffta, fftb;

vector<cd> decimate(vector<cd>& a) {
    int n = a.size();
    if (n==1) return vector<cd>(1, a[0]);
    vector<cd> w(n);
    for (int i = 0; i < n; ++i) {
        double alpha = -2 * pi * i / n;
        w[i] = cd(cos(alpha), sin(alpha));
    }
    vector<cd> A0(n / 2), A1(n / 2);
    for (int i = 0; i < n / 2; i++) {
        A0[i] = a[i * 2];
        A1[i] = a[i * 2 + 1];
    }
    vector<cd> y0 = decimate(A0);
    vector<cd> y1 = decimate(A1);
    vector<cd> y(n);
    for (int k = 0; k < n / 2; k++) {
        y[k] = y0[k] + w[k] * y1[k];
        y[k + n / 2] = y0[k] - w[k] * y1[k];
    }
    return y;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> sa >> sb;
    a.resize(sa.length());
    b.resize(sb.length());
    for (int i = 0; i < sa.length(); ++i) a[sa.length()-1-i] = (double) sa[i]-'0';
    for (int i = 0; i < sb.length(); ++i) b[sb.length()-1-i] = (double) sb[i]-'0';
    ffta = decimate(a);
    fftb = decimate(b);
    for (int i = 0; i < ffta.size(); ++i) cout << ffta[i] << " ";
    cout << "\n";
    for (int i = 0; i < fftb.size(); ++i) cout << fftb[i] << " ";
    cout << "\n";
    return 0;
}