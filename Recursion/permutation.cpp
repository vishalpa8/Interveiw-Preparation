#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

set<string> ans;
void findpermutation(string s,int index, int n){
    if(index == n){
        ans.insert(s);
        return;
    }
    
    for(int i=index; i<=n; i++){
        swap(s[i],s[index]);
        findpermutation(s,index+1, n);
        swap(s[i],s[index]);
    }
}

void generatePermuation(string s, string output, set<string> &an) {
    if (s.size() == 0) an.insert(output);
 
    for (int i = 0; i < (int)s.length(); i++) {
        generatePermuation(s.substr(0, i) + s.substr(i + 1), output + s[i], an);
    }
}

int main(){
    fast_io;

    string s;
    cin >> s;
    int n = s.length();

    // findpermutation(s,0,n-1);
    //generatePermutation(s,"",ans);



    return 0;
}