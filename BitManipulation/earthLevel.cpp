#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int earthLevel(int k){
    int ans = 0;
    while(k > 0){
        k &= (k-1);
        ans++;
    }
    return ans;   
}

int main(){
    fast_io;

    cout << earthLevel(7) << endl;



    return 0;
}