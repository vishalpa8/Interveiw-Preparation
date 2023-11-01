#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

bool isBalanced(string input){
      stack<char> st;
        
    for(auto c : input){
        if(c >= 'a' && c <= 'z'){
            continue;
        }
        switch(c){
            case '[':
                st.push(']');
                break;
            case '(':
                st.push(')');
                break;
            case '{':
                st.push('}');
                break;
            default: 
                if(st.empty() || st.top() != c) return false;
                else{
                    st.pop();
                }
        }
    }
    return !st.size();
}

int main(){
    fast_io;
    string input = "{ab(ai[wioo(w])}";

    if(isBalanced(input)){
        cout << "Balanced!!";
    }
    else{
        cout << "Not Balanced!!";
    }


    return 0;
}