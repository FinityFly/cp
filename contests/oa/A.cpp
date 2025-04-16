#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
/*

*/

int solution(int A, int B)
{
    int maxLen = 0;
    // 1. cut the bigger piece into 4 pieces
    int bigger = max(A, B), smaller = min(A, B);
    maxLen = max(maxLen, bigger / 4);
    // 2. cut the bigger piece into 3 pieces
    maxLen = max(maxLen, min(bigger / 3, smaller));
    // 3. cut them each into 2 pieces
    maxLen = max(maxLen, min(bigger / 2, smaller / 2));
    return maxLen;
}