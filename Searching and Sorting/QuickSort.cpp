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



void quickSort(vector<int> &v, int s, int e){
    if(s >= e){
        return;
    }

    int p = partition(v,s,e);
    quickSort(v,s,p-1);
    quickSort(v,p+1,e);
}


int main(){
    fast_io;

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    quickSort(v,0,n-1);
    
    for(auto a : v){
        cout << a << " ";
    }


    return 0;
}