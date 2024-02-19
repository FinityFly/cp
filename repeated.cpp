#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long repeatedString(string s, long n) {
    long output = 0;
    string fullstring;
    int occurances = 0;
    for(long j=0;j<s.length();++j){
        if(s[j] == 'a'){
            occurances++;
        }
    }
    long multiply = round(n/s.length());
    output = occurances * multiply;
    int remainder = n % s.length();
    for(long i=0;i<remainder;++i){
        if(s[i] == 'a'){
            output++;
        }
    }
    return output;
}

int main()
{
    string s = "abcac";
    long n = 10;
    long result = repeatedString(s, n);
    cout << result;
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }

    return 0;
}
