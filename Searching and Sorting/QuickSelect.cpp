#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int partition(vector<int> &v, int s, int e){
    int pivot = v[e];
    int i = s - 1;

    for(int j = s; j <= e; j++){
        if(v[j] < pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[e]);

    return i + 1;
}

int quickSelect(vector<int> &v, int s, int e, int k){
    int p = partition(v,s,e);
    if(p == k){
        return v[p];
    }

    if(p > k){
        return quickSelect(v,s,p-1,k);   
    }

    return quickSelect(v,p+1,e,k);
}

int main(){
    fast_io;

    vector<int> v{10,5,6,2,4,0}; // 0 2 4 5 6 10
    int k = 3;

    cout << quickSelect(v,0,5,k) << "\n";



    return 0;
}