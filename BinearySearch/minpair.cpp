#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
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

pair<int,int> minPair(vector<int> a1, vector<int> a2){
    sort(val(a2));
    int diff = INT_MAX;
    int p1,p2;

    for(auto x : a1){
        auto lb = lower_bound(val(a2),x) - a2.begin();

        if(lb >= 1 && x - a2[lb-1] < diff){
            diff = x - a2[lb-1];
            p2 = x;
            p1 = a2[lb-1];
        }

        if(lb!=sze(a2) and a2[lb] - x < diff){
            diff = a2[lb] - x;
            p1 = x;
            p2 = a2[lb];
        }

    }

    return {p1,p2};

}


int main(){
    fast_io;

    vector<int> a{23,5,10,17,30};
    vector<int> b{26,134,135,14,19};

    auto ans = minPair(a,b);

    cout << ans.first << " " << ans.second << "\n";


    return 0;
}