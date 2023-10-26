#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

string keypad[100] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void generateKeypad(string input, string output, int index = 0){
    if(input[index] == '\0'){
        cout << output << "\n";
        return;
    }
    int digit = input[index] - '0';   //23 
    if(digit == 0 || digit == 1){
        generateKeypad(input, output, index + 1);
    }
    
    for(int i=0; i<keypad[digit].size(); i++){
        generateKeypad(input,output + keypad[digit][i],index+1);
    }
    return;
}

int main(){
    fast_io;
    string input;
    cin >> input;

    generateKeypad(input,"");


    return 0;
}