#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

vector<char> FindFirstNonRepeatingCharacter(string input){
    queue<char> q;
    unordered_map<char,int> mp;
    vector<char> v;
    //aabcbcd
    for(auto ch : input){
        q.push(ch);
        mp[ch]++;

        while(!q.empty()){
            char val = q.front();
            if(mp[val] > 1){
                q.pop();
            }
            else{
                v.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            v.push_back('0');
        }
    }

    return v;
}

int main(){
    fast_io;
    string s = "aabcbcd";

    auto val = FindFirstNonRepeatingCharacter(s);

    for(auto a : val){
        cout << a << " ";
    }



    return 0;
}