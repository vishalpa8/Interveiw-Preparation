#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int minimumMergingRopes(int arr[], int n){
    priority_queue<int,vector<int>,greater<int>> pq(arr,arr+n);

    int cost = 0;
    while(pq.size() > 1){
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();

        int newLen = A + B;
        cost += newLen;
        pq.push(newLen);
    }

    return cost;
}

int main(){
    fast_io;

    int arr[] = {4,2,3,6};
    int n = 4;
    
    cout << minimumMergingRopes(arr,n);



    return 0;
}