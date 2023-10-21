#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int largestBand(vector<int> v){
    unordered_set<int> s;
    int ans = 1;

    for(auto a : v){
        s.insert(a);
    }

    for(auto ele : v){
        int parent = ele - 1;
        if(s.find(parent) == s.end()){
            int count = 0;
            int no = parent + 1;
            while(s.find(no) != s.end()){
                // cout << no << " ";
                ++count;
                no++;
            }
            // cout << "\n";
            ans = max(count,ans);
        }
    }

    return ans;
}

int main(){
    fast_io;

    vector<int> v{1,9,3,0,18,5,2,18,10,7,12,6};

    cout << largestBand(v); 


    return 0;
}