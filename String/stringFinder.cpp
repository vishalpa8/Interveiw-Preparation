#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

void findOccurence(string paragraph, string word){
     /* we are taking -1 as in loop because if we can't find that particular word then it
        will give us a very long integer value which we are converting directly into unsigned int.
     */
        int index = 0; 
        while(index != -1){
            index = paragraph.find(word,index);
            if(index != -1){
                cout << "occurence: " << index << "\n"; 
                index++;
            }
        }

}

int main(){
    fast_io;

    string s;
    getline(cin,s);
    string word;
    cin >> word;

    findOccurence(s,word);


    return 0;
}