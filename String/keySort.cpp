#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

string extractStringAtKey(string str, int key){
    char *s = strtok((char*)str.c_str()," ");

    while(key > 1){
        s = strtok(NULL," ");
        key--;
    }

    return (string)s;
}

int convertToInt(string s){
    // return stoi(s);
    int ans = 0;
    int p = 1;

    for(int i=s.size()-1; i>=0; i--){
        int n = s[i] - '0';     //133   -> 3*1 -> 3 * 10 -> 1 * 100 => 133
        ans += (n * p); 
        p = p * 10;

    }

    return ans;
}

bool ncompare(pair<string,string> p1, pair<string,string> p2){
    int key1 = convertToInt(p1.second);
    int key2 = convertToInt(p2.second);
    return key1 < key2;
}

bool scompare(pair<string,string> p1, pair<string,string> p2){
    string key1 = p1.second;
    string key2 = p2.second;
    return key1 < key2;
}



int main(){
    fast_io;

    int n;
    cin >> n;

    string temp;
    vector<string> v;

    for(int i=0; i<n; i++){
        getline(cin,temp);
        v.push_back(temp);
    }

    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;

    vector<pair<string,string>> vp;

    for(int i=0; i<n; i++){
        vp.push_back({v[i],extractStringAtKey(v[i],key)});
    }

    if(ordering == "numeric"){
        sort(vp.begin(),vp.end(),ncompare);
    }
    else{
        sort(vp.begin(),vp.end(),scompare);
    }

    if(reversal == "true"){
        reverse(vp.begin(),vp.end());
    }

    for(int i=0; i<n; i++){
        cout << vp[i].second << "\n";
    }

    return 0;
}