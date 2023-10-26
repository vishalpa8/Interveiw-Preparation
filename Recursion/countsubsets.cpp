#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int countSubsets(vector<int> arr, int i, int n, int x){
    if(i == n){
        if(x == 0){
            return 1;
        }
        return 0;
    }

    return countSubsets(arr,i+1,n,x - arr[i]) + countSubsets(arr,i+1,n,x);
}

int main(){
    fast_io;

    vector<int> v{1,2,3,4,5};
    int sum = 5;

    cout << countSubsets(v,0,sze(v),sum);



    return 0;
}