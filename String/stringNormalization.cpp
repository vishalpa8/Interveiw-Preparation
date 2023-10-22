#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int skip_whitespace(const string &sentence, int idx) {
    while (idx < sentence.length() && sentence[idx] == ' ') {
        idx += 1;
    }
 
    return idx;
}
 
int normalize_word(string &sentence, int idx) {
    if (idx < sentence.length() && sentence[idx] != ' ') {
        sentence[idx] = toupper(sentence[idx]);
        idx += 1;
    }
 
    while (idx < sentence.length() && sentence[idx] != ' ') {
        sentence[idx] = tolower(sentence[idx]);
        idx += 1;
    }
 
    return idx;
}
 
string normalize(const string &sentence) {
    string copy = sentence;
    int idx = 0;
 
    while (idx < copy.length()) {
        idx = skip_whitespace(copy, idx);
        idx = normalize_word(copy, idx);
    }
 
    return copy;
}

int main(){
    fast_io;
    string s;
    getline(cin,s);

    cout << normalize(s);


    return 0;
}