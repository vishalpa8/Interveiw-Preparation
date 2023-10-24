#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

float square_root(int n, int p){
    int s = 0, e = n;
    float ans = 0;

    while(s <= e){
        int mid = (e + s)/2;

        if(mid * mid == n){
            return mid;
        }
        else if(mid * mid <= n){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }

    float inc = 0.1;   

    for(int i=1; i<=p; i++){
        while(ans * ans <= n){
            ans += inc;
        }
        ans -= inc;
        inc /= 10.0;
    }

    return ans;
}

int main(){
    fast_io;
    int n,p;
    cin >> n >> p;

    cout << square_root(n,p) << "\n";



    return 0;
}