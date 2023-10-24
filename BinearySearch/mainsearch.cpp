#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int binearSearch(vector<int> v, int s, int e,int key){

    while( s <= e){
        int mid = (s + e)/2;

        if(v[mid] == key){
            return mid;
        }
        else if(v[mid] > key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }

    return -1;
}

int main(){
    fast_io;




    return 0;
}