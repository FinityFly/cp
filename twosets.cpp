#include <iostream>
#include <vector>
#include <set>

using namespace std;

int getTotalX(vector<int> a, vector<int> b) {
    int output = 0;
    int m = a.size();
    int n = b.size();
    int num;
    vector<int> temp;
    vector< vector<int> > factors;
    vector<int> bnums;
    vector<int> op;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0;i<n;++i){
        temp.clear();
        num = b[i];
        for(int j=1;j<=num;++j){
            if(num%j==0)
                temp.push_back(j);
        }
        factors.push_back(temp);
    }
    if(n!=1){
        for(int j=0;j<n-1;++j){
            std::set_intersection(factors[j].begin(),factors[j].end(), factors[j+1].begin(),factors[j+1].end(),back_inserter(bnums));
            factors[j+1] = bnums;
            if(j != n-2){
                bnums.clear();
            }
        }
    }else{
        bnums = factors[0];
    }
    cout << "bnums:\n";
    for (int i = 0; i < bnums.size(); ++i){
        cout << bnums[i] << " ";
    }

    cout << "\nfactors:\n";
    for (int i = 0; i < factors.size(); i++) { 
        for (int j = 0; j < factors[i].size(); j++) 
            cout << factors[i][j] << " "; 
        cout << "\n"; 
    }
    cout << "\nfinal:\n";
    for (int i = 0; i < bnums.size(); ++i){
        cout << bnums[i] << " ";
    }
    bool notdivisible;
    for(int l=0;l<bnums.size();++l){
        notdivisible = false;
        // cout << "\nbnums: " << bnums[l] << "\n";
        for(int k=0;k<m;++k){
            // cout << "\na set: " << a[k] << "\n";
            if(bnums[l] % a[k] != 0){
                notdivisible = true;
                break;
            }
        }
        if(!notdivisible){
            output += 1;
            op.push_back(bnums[l]);
            cout << "hi\n";
        }
    }
    cout << "\nop:\n";
    for (int i = 0; i < op.size(); ++i){
        cout << op[i] << " ";
    }
    return output;
}

int main()
{
    int arr1[] = {1};
    vector<int> a(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
    int arr2[] = {100};
    vector<int> b(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
    int result = getTotalX(a, b);
    cout << "\n" << result;
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }

    return 0;
}
