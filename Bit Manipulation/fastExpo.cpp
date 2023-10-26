#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)


long long int power(ll x, ll n){
    long long int main_ans = 1;
    while(n > 0){
        int ans = n & 1;
        
        if(ans){
            main_ans *= x;
        }
        
        x *= x;
        n = n >> 1;
	}
    return main_ans;
}

int main(){
    fast_io;

    ll a, n;
    cin >> a >> n;
    cout << power(a,n)<< "\n";


    return 0;
}