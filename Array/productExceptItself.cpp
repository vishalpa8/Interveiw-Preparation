#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

vector<int> productExceptSelf(vector<int>& nums) {
    const int n = nums.size();
    vector<int> answer(n),frombegin(n),fromlast(n);
    frombegin[0] = 1;
    fromlast[0] = 1;
    for(int i=1; i<n; i++){
        frombegin[i] = frombegin[i-1]*nums[i-1];
        fromlast[i] = fromlast[i-1] * nums[n-i];
    }
                                
    for(int i=0; i<n; i++){
        answer[i] = frombegin[i] * fromlast[n-1-i];
    }
                                
    return answer;
}

int main(){
    fast_io;

    vector<int> arr{1,9,3,4,15};

    auto ans = productExceptSelf(arr);

    for(auto a : ans){
        cout << a << " ";
    }



    return 0;
}