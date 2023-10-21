#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

bool flag(int arr[],int i,int n){
    if(i == 0){
        return arr[i] > arr[i+1];
    }  
    if(i == n-1){
        return arr[i] < arr[i-1];
    }      

    return arr[i] > arr[i+1] or arr[i] < arr[i-1];
}
vector<int> printUnsorted(int arr[], int n) {
    int largest = INT_MIN;
    int smallest = INT_MAX;

    if(n == 1){
        return {0,0};
    }

    for(int i=0; i<n; i++){
        if(flag(arr,i,n)){
            largest = max(arr[i],largest);
            smallest = min(arr[i],smallest);
        }

    }
    if(smallest == INT_MAX){
        return {0,0};
    }
    int left = 0;

    while(smallest >= arr[left]){
        left++;
    }
    int right = n-1;

    while(largest <= arr[right]){
        right--;
    }

    return {left,right};
    
}

int main(){
    fast_io;
    int n = 11;
    int arr[] = {1,2,3,4,5,8,6,7,9,10,11};

    auto v = printUnsorted(arr,n);

    cout << v[0] << " " << v[1] << endl;


    return 0;
}