#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int countWays(int n){
    if( n < 0){
        return 0;
    }
    if(n == 0 || n == 1){
        return 1;
    }

    return countWays(n-1) + countWays(n-2) + countWays(n-3);
}

int main(){
    fast_io;

    int n;
    cin >> n;

    cout << countWays(n) << "\n";
    return 0;
}