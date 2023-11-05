#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int countTriplets(vector<int> arr, int r){
    int n = arr.size();
    unordered_map<long,long> right,left;

    for(auto x : arr){
        right[x]++;
        left[x] = 0;
    } 

    int ans = 0;

    for(int i=0; i<n; i++){
        right[arr[i]]--;
        if(arr[i] % r == 0){
            long b = arr[i];
            long a = arr[i] / r;
            long c = arr[i] * r;

            ans +=  left[a] * right[c];
        } 
        left[arr[i]]++;
    }

    return ans;
}

int main(){
    fast_io;

    int n,r;
    cin >> n >> r;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }



    return 0;
}