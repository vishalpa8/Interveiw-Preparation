#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)


void merge(vector<int> &v, int s, int e){
    vector<int> temp;
    int m = (s + e)/2;
    int i = s,  j = m+1;
    
    while(i<=m and j<=e){
        if(v[i] <= v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
        }
    }

    while(i <= m){
        temp.push_back(v[i++]);
    }
    while(j <= e){
        temp.push_back(v[j++]);
    }
    int k = 0;
    for(int idx = s; idx <= e; idx++){
        v[idx] = temp[k++];
    }
     
    return;
}


void mergeSort(vector<int> &v, int s, int e){
    if(s >= e){
        return;
    }   
    int mid = (s + e)/2;
    mergeSort(v,s,mid);
    mergeSort(v,mid+1,e);
    merge(v,s,e);

    return;
}

int main(){
    fast_io;
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    mergeSort(v,0,n-1);

    for(auto a : v){
        cout << a << " ";
    }


    return 0;
}