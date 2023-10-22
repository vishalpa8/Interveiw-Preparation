#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

void sortSubsequence(string s, string o, vector<string> &v){
    if(s.empty()){
        if(o.empty()){
            return;
        }
        v.push_back(o);
        return;
    }

    sortSubsequence(s.substr(1),o+s[0],v);
    sortSubsequence(s.substr(1),o,v);
}

bool compare(string s1, string s2){
    if(s1.length() == s2.length()){
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main(){
    fast_io;
    string s;
    cin >> s;

    vector<string> output;

    sortSubsequence(s,"",output);
    sort(output.begin(),output.end(),compare);

    for(auto a : output){
        cout << a << " ";
    }
    



    return 0;
}