#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

vector<int> targetSum(vector<int> &v, int target){
    unordered_set<int> s(v.begin(),v.end());

    for(auto n : v){
        int sum = target - n;
        if(s.find(sum) != s.end()){
            return {n,sum};
        }
        s.insert(n);
    }

    return {};

}

int main(){
    fast_io;

    vector<int> v{10,5,2,3,-6,9,11};
    int target = 4;

    auto ans = targetSum(v,target);

    cout << ans[0] << " " << ans[1] << "\n";


    return 0;
}