#include <iostream>
#include <vector>

using namespace std;

int birthdayCakeCandles(vector<int> candles) {
    int n = candles.size();
    int max = candles[0];
    int output = 0;
    for(int i=1;i<n;++i){
        if(candles[i]>max){
            max = candles[i];
            output = 1;
            cout << "log 1\n";
        }else if(candles[i]==max){
            output += 1;
            cout << "log 2\n";
        }
    }
    return output;
}

int main()
{
    int arr[] = {3, 2, 1, 3};
    vector<int> scores(arr, arr + sizeof(arr)/sizeof(arr[0]));
    int result = birthdayCakeCandles(scores);
    cout << result;
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }

    return 0;
}
