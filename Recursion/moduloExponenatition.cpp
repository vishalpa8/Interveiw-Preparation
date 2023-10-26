#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

ll mod = 1000000007;

long long int power(int a, int b){
    if(b == 1){
        return a;
    }
    return (a * power(a,b-1)) % mod;
}

int main(){
    fast_io;

    int a,b;
    cin >> a >> b;

    cout << power(a,b);


    return 0;
}