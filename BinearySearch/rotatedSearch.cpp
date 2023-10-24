#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int rotated_search(vector<int>v, int s, int e, int key){

    while(s <= e){
        int mid = (s + e)/2;

        if(v[mid] == key){
            return mid;
        }
        
        if(v[s] <= v[mid]){
            if(key >= v[s] && key < v[mid]){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        else{
            if(key > v[mid] && key <= v[e]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        /*
            if array contains duplicate element in rotate array then we have to just shrink the array by duplicates
            for that we can direcly reduce the array. put the this condition just above the if else condition on 15 line.
            if((v[s] == v[mid]) && (v[e] == v[mid])){
                s++;
                e--;
            }
        */
    }

    return -1;
}

int main(){
    fast_io;

    vector<int> v{4,5,6,7,0,1,2,3};
    int key;
    cin >> key;

    cout << rotated_search(v,0,v.size()-1,key);



    return 0;
}