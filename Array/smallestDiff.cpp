#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

pair<int,int> minDifference(vector<int> a,vector<int> b){
    int i=0,j=0;
    int first = 0, second = 0;
    int mn = INT_MAX;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
  
    while(i < a.size() && j < b.size()){
        int val = abs(a[i]-b[j]);
        if(val < mn){
            mn = val;
            first = a[i];
            second = b[j];
        }
        if(a[i] < b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    
    return {first,second};   
}

int main(){
    fast_io;

    vector<int> a{23,5,10,17,30};
    vector<int> b{26,134,135,14,19};

    auto ans = minDifference(a,b);

    cout << ans.first << " " << ans.second << "\n";


    return 0;
}