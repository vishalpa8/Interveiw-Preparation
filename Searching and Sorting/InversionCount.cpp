#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int merge(vector<int> &v, int s, int e){
    vector<int> temp;
    int m = (s + e)/2;
    int i = s,  j = m+1;
    int count = 0;
    while(i<=m and j<=e){
        if(v[i] <= v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            count += (m - i  + 1);
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
     
    return count;
}


int inversion_count(vector<int> &v, int s, int e){
    if(s >= e){
        return 0;
    }   
    int mid = (s + e)/2;
    int c1 = inversion_count(v,s,mid);
    int c2 = inversion_count(v,mid+1,e);
    int ci = merge(v,s,e);

    return c1 + c2 + ci;
}

int main(){
    fast_io;
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    cout << inversion_count(v,0,n-1);


    return 0;
}