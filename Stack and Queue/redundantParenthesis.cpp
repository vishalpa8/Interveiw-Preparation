#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

/*
    This problem is basically for checking the extra brackets, using into your
    expression if it is then, it tatall depends on to the operator.
*/

bool redundantParenthesis(string str){
    stack<char>s;

    for(auto ch : str){
        if(ch != ')'){
            s.push(ch);
        }
        else{
            bool operator_found = false;
            while(!s.empty() && s.top() != '('){
                char top = s.top();
                if(top == '+' or top == '-' or top == '*' or top == '/'){
                    operator_found = true;
                }
                s.pop();
            }
            s.pop();
            
            if(!operator_found){
                return true;
            }
        }
    }

    return false;
}

int main(){
    fast_io;

    string input = "((a+b)+(cd))";

    if(redundantParenthesis(input)){
        cout << "yes it contains";
    }
    else{
        cout << "No it doesn't have";
    }


    return 0;
}