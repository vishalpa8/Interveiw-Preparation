#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

 int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int largest = 0;

        for(int i=1; i<=n-2;){
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                int j = i;
                int cnt = 1;
                while( j >= 1 && arr[j] > arr[j-1]){
                    j--;
                    cnt++;
                }
                while(i <= n-2 && arr[i] > arr[i+1]){
                    i++;
                    cnt++;
                }
                largest = max(cnt,largest);
            }
            else{
                i++;
            }
        }

    return largest;
}


int main(){
    fast_io;

    vector<int> v{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,-4};

    cout << longestMountain(v) << "\n";


    return 0;
}