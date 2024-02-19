#include <iostream>
#include <vector>

using namespace std;

vector<int> breakingRecords(vector<int> scores, int n) {
    vector<int> output;
    output.push_back(0);
    output.push_back(0);
    int max, min;
    max = scores[0];
    min = scores[0];
    for (int i=1;i<n;++i){
        if(scores[i] > max){
            output[0] += 1;
            max = scores[i];
        }else if(scores[i] < min){
            output[1] += 1;
            min = scores[i];
        }
    }
    return output;
}

int main()
{
    int arr[] = {12, 24, 10, 24};
    vector<int> scores(arr, arr + sizeof(arr)/sizeof(arr[0]));
    int n = scores.size();
    vector<int> result = breakingRecords(scores, n);
    for(int i=0;i<result.size();++i){
      cout << result[i] << " ";
    }

    return 0;
}
