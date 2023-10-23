#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int binearSearch(vector<vector<int>> &v, int i,int s, int e,int key){

    while( s <= e){
        int mid = (s + e)/2;

        if(v[i][mid] == key){
            return mid;
        }
        else if(v[i][mid] > key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }

    return -1;
}

pair<int,int> search(int m, int n, vector<vector<int>> v, int k){ 

        for(int i=0; i<v.size(); i++){
            int index = binearSearch(v,i,0,n-1,k);
            if(index != -1){
                return {i,index};
            }
        }
    return {-1,-1};
}

//optimized way;
pair<int,int> search(vector<vector<int>> v, int n, int m, int k) {
    int i = 0, j = m - 1;
    
    while( i < n && j >= 0){
        if(v[i][j] == k){
            return {i,j};
        }
        else if(v[i][j] > k){
            j--;
        }
        else{
            i++;
        }
    }    
        // mid > k
    return {-1,-1};
}

int main(){
    fast_io;
    int m,n;
    cin >> m >> n;

    vector<vector<int>>v;

    for(int i=0; i<m; i++){
        vector<int> an;
        for(int j=0; j<n; j++){
            int value; cin >> value;
            an.push_back(value);
        }
        v.push_back(an);
    }
    int key;
    cin >> key;

    auto ans = search(v,m,n,key);

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}