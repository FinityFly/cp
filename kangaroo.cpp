#include <iostream>
#include <vector>

using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
    int jump = 0;
    while(jump<3000){ //change when needed
        if(x1==x2){
            cout << jump;
            return "YES";
        }
        x1 += v1;
        x2 += v2;
        jump++;
    }
    return "NO";
}

int main()
{
    int x1=4, v1=3, x2=3, v2=2;
    string result = kangaroo(x1, v1, x2, v2);
    cout << result;
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }

    return 0;
}
