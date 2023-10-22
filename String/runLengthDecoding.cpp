#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

string compressString(const string &str){   
    //complete the function to return output string
  
    unordered_map<char,int> mp;

    for(char c : str){
        mp[c]++;
    }
    string ans;

    for(auto ch : str){
        if(mp.find(ch) != mp.end()){
            ans += (ch + to_string(mp[ch]));
            mp.erase(ch);
        }
     }


    return ans.size() > str.size() ? str : ans;
    
   
}

int main(){
    fast_io;
    string s;
    cin >> s;

    cout << compressString(s);



    return 0;
}