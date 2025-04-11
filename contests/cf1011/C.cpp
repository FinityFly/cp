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

/*
10111
01110

11000
01111

11100
10011

100100
011011

add to the first alternating bit (0 1 pair) to the right of each matching 1 bit in each number

0010000000000
1000000000000


100100100100100100100
010010010010010010100

100100100100101000000
010010010010010110000

000000000000000011100


0111
1001

01110
10000

if you see a 1 in both numbers, add 1 to the right of the first 0 1 pair to the right of the 1 in both numbers
if you can't find a 0 1 pair to the right of the 1 in both numbers, add 1 to the 1 1 pair and go up to the next 1 1 pair
*/

ll x, y;

void solve()
{
    cin >> x >> y;
    if (x == y)
    {
        cout << "-1\n";
        return;
    }
    else if ((x & y) == 0)
    {
        cout << "0\n";
        return;
    }

    ll k = 0;
    ll bit = 1;
    ll origX = x, origY = y;

    while (bit <= 1e18)
    {
        // Check if this bit is set in both x and y
        if ((x & bit) && (y & bit))
        {
            ll tempBit = bit;
            int cnt = 0;

            // Look for the first position to the right where either x or y has a bit set
            while (((x & (tempBit >> 1)) | (y & (tempBit >> 1))) == 0)
            {
                tempBit >>= 1;
                cnt++;
                if (tempBit == 0)
                    break; // Prevent going too far
            }

            // If we reached the end or no bits set to the right
            if (tempBit == 0 || ((x & (tempBit >> 1)) | (y & (tempBit >> 1))) == 0)
            {
                k += bit;
                x += bit;
                y += bit;
            }
            else
            {
                // We found a position where x or y has a bit set, go back to original bit
                tempBit = bit >> cnt; // This is where we found a set bit
                k += tempBit;
                x += tempBit;
                y += tempBit;
            }

            // Check if our solution works
            ll newX = origX + k;
            ll newY = origY + k;
            if ((newX + newY) == (newX ^ newY))
            {
                break; // We found a valid k
            }
        }

        // Move to the next bit
        if (bit > (1e18 / 2))
            break; // Prevent overflow
        bit <<= 1;
    }

    cout << k << "\n";
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
