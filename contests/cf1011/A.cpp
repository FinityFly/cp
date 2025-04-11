#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll;
typedef map<ll, ll> mll;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e - 1; i >= (ll)s; i--)
#define TRAV(a, c) for (auto a : c)
#define all(x) x.begin(), x.end()

ll read()
{
    ll s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
    }
    return s * f;
}
template <class T>
string to_string(T s, T e)
{
    if (s == e)
        return "[]";
    string ret = "[" + to_string(*s++);
    while (s != e)
        ret += ", " + to_string(*s++);
    return ret + "]";
}

#define MM 100001
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define FASTIO ;
// #define PRECISION ;
// #define FILE ;

// #define SINGLE ;
#define MULTIPLE ;
// #define GOOGLE ;

ll n, k;
unordered_set<char> u;

void solve()
{
    u.clear();
    cin >> n >> k;
    string s;
    cin >> s;
    ll cnt = 0;
    FOR(i, 0, n / 2)
    {
        if (s[i] < s[n - i - 1])
        {
            cout << "YES\n";
            return;
        }
        else if (s[i] > s[n - i - 1])
        {
            if (k >= 1)
            {
                cout << "YES\n";
                return;
            }
            else if (k == 0)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    FOR(i, 0, n)
    {
        u.insert(s[i]);
    }
    if (u.size() == 1)
    {
        cout << "NO\n";
        return;
    }
    if (k >= 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
#ifdef FASTIO
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
#ifdef PRECISION
    cout << fixed << setprecision(10);
#endif
#ifdef FILE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef SINGLE
    solve();
#endif
#ifdef MULTIPLE
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        solve();
    }
#endif
#ifdef GOOGLE
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
#endif
}
