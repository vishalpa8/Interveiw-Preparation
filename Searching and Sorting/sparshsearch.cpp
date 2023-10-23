#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int sparsh_search(string str[], int n, string key){
    int s = 0;
    int e = n-1;


    while(s <= e){
        int mid = (s + e)/2;
        int left = mid - 1;
        int right = mid + 1;
        
        if(str[mid] == ""){
            while(1){
                if(left < s && right > e){
                    return -1;
                }
                else if(left >= s && str[left] != ""){
                    mid = left;
                    break; 
                }  
                else if(right <= e && str[right] != ""){
                    mid = right;
                    break;
                }  
                left--;
                right++;
            }
        }
        if(str[mid] == key){
            return mid;
        }
        else if(str[mid] > key){
            e = mid - 1 ;
        }
        else{
            s = mid + 1;
        }
    }

    
    return -1;
}


int main(){ 
    fast_io;

    string str[] = {"ai","","","bat","","","car","cat","","","dog","e"};
    int n = 12;
    string word;
    cin >> word;

    cout << sparsh_search(str,n,word) << "\n";



    return 0;
}