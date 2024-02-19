#include <iostream>
#include <vector>

using namespace std;

int jumpingOnClouds(vector<int> c) {
    int output = 0;
    int n = c.size();
    int cloud = 0;
    int cond;
    if(n==2){
        return 1;
    }
    while(cloud != n-1){
        if(c[cloud+2]==0){
            cloud += 2;
            output++;
        }else{
            cloud++;
            output++;
        }
    }
    return output;
}

int main()
{
    int arr[] = {0, 0};
    vector<int> c(arr, arr + sizeof(arr)/sizeof(arr[0]));
    int result = jumpingOnClouds(c);
    cout << result;
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }

    return 0;
}
