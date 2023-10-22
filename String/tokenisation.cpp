#include<iostream>
#include<sstream>
#include<cstring>
#include<vector>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

//Inbuilt
void strstream(char *s){
    stringstream ss(s);

    string token;
    vector<string> tokens;

    while(getline(ss,token,' ')){
        tokens.push_back(token);
    }

    for(auto tok : tokens){
        cout << tok << ",";
    }
}

void strtok_use(char *s){
    char* token = strtok(s," ");

    //make sure it should be static;

    while(token != NULL){
        cout << token << ",";
        token = strtok(NULL," ");
    }
    
}


//Self Made;
char* mystrtok(char* str, char delim){
    static char *input = NULL;
   
    if(str != NULL){
        input = str;
    }
    if(input == NULL){
        return NULL;
    }
    

    char *token = new char[strlen(input)+1];
    int i = 0;

    for(; input[i] != '\0'; i++){
        if(input[i] != delim){
            token[i] = input[i];
        }
        else{
            token[i] = '\0';
            input = input + i + 1;
            return token;
        }
    }

    token[i] = '\0';
    input = NULL;

    return token;

}

int main(){
    fast_io;
    char input[1000];
    cin.getline(input,1000);

    // strstream(input);
    // cout << endl;
    // strtok_use(input);

    char* token = mystrtok(input,' ');
    while(token != NULL){
        cout << token << "\n";
        token = mystrtok(NULL,' ');
    }

    return 0;
}