#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

 void generateBrackets(string output, int n, int open, int close, int index){
    if(index == 2 * n){
        cout << output << "\n";
        return;
    }

    if(open < n){
        generateBrackets(output + '(', n , open + 1, close, index + 1);
    }
    if(close < open){
        generateBrackets(output + ')', n , open, close + 1, index + 1);
    }

 }

int main(){
    fast_io;

    int n;
    cin >> n;
    generateBrackets("",n,0,0,0);

    return 0;
}