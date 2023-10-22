#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

void space20(char *s){
    int space = 0;
    int size = strlen(s);
    
    for(int i=0; i<size; i++){
        char c = s[i];
        if(c == ' ') space++;
    }
    int idx = size + (2 * space);
    s[idx] = '\0';

    for(int i=size-1; i>=0; i--){
        if(s[i] == ' '){
            s[idx - 1] = '0';
            s[idx - 2] = '2';
            s[idx - 3] = '%';
            idx -= 3;
        }
        else{
            s[--idx] = s[i];
        }
    } 
}

int main(){
    fast_io;

    char s[1000];
    cin.getline(s,1000);

    space20(s);
    cout << s << " ";


    return 0;
}