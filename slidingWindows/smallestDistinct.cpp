#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string str){
    // Complete this method
    set<int> s;
    unordered_map<char,int> mp;
    
    for(char ch :  str){
        s.insert(ch);
    }
    
    int size = s.size();
    int n = str.size();
    int j = 0;
    int mn = INT_MAX;
    int start = 0, end = 0;
    
    for(int i=0; i<n; i++){
        mp[str[i]]++;
        while(j <= i && mp.size() == size){
            int len = i - j + 1;
            if(len < mn){
                mn = len;
                start = j;
                end = len;
            }
            mp[str[j]]--;
            if(mp[str[j]] == 0){
                mp.erase(str[j]);
            }
            
            j++;
        }
        
        
    }
    return str.substr(start,end);
    
}

int main(){
    string s;
    cin >> s;


    cout << smallestWindow(s);
}