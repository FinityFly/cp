#include <iostream>
#include <vector>

using namespace std;

int hurdleRace(int k, vector<int> height) {
    int output = 0;
    bool cantJump;
    for(int i=0;i<height.size();++i){
        if(k >= height[i]){
            continue;
        }else{
            cantJump = true;
            while(cantJump){
                k += 1;
                output += 1;
                if(k == height[i]){
                    cantJump = false;
                }
            }
        }
    }
    return output;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 2};
    vector<int> height(arr, arr + sizeof(arr)/sizeof(arr[0]));
    int k = 1;
    int result = hurdleRace(k, height);
    cout << result;
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }

    return 0;
}
