#include <bits/stdc++.h>
using namespace std;

/*
INPUT:
30 35
60 100
9 10
 */

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b, c, games=0;
    cin >> n >> a >> b >> c;
    while (n > 0) {
        if (a + 1 == 35) {
            a = 0;
            n += 29;
            ++games;
        } else {
            a++;
            n--;
            ++games;
        }
        if (b + 1 == 100 && n > 0) {
            b = 0;
            n += 59;
            ++games;
        } else if (n == 0) {
            break;
        } else {
            b++;
            n--;
            ++games;
        }
        if (c + 1 == 10 && n > 0) {
            c = 0;
            n += 8;
            ++games;
        } else if (n == 0) {
            break;
        } else {
            c++;
            n--;
            ++games;
        }
    }
    cout << "Martha plays " << games << " times before going broke.\n";
    return 0;
}