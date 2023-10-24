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

int frequecy_count(vector<int> v, int n,int key){
        int index = binearSearch(v,0,n-1,key);
        if(index == -1){
            return -1;
        }
        int count = 1;
        int left = index - 1;
        int right = index + 1;

       while(left >= 0 && v[left] == key){
            count++;
            left--;
       }

       while(right < n && v[right] == key){
            count++;
            right++;
       }

       return count;
}

int main(){
    fast_io;

    vector<int> v{0,1,1,1,2,2,2,3,3,4,4,5,5};
    int n = v.size();
    int key;
    cin >> key;

    cout << frequecy_count(v,n,key) << "\n";
    cout << upper_bound(v.begin(),v.end(),key) - lower_bound(v.begin(),v.end(),key);

    /* for creating our own lower and upper bound, when you find the element in 
       binearysearch just copy the element ans = mid - 1 for lower 
       and ans = mid + 1 upper. 
       like:- 
       for lower bound.
        if(arr[mid] == key){
            end = mid - 1;
            ans = mid;
        for upper bound.
        if(arr[mid] == key)
            ans = mid;
            start = mid + 1;
       }
       it should also works, you can also use that technique to solve many problems.
    */

    return 0;
}