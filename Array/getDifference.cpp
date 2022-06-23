#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int mx = 0;
        int mn = 0;
        int res = arr[n-1] - arr[0];
        
        for(int i=1; i<n; i++){
            if(arr[i] >= k){
                mx = max(arr[i-1] + k, arr[n-1] - k);
                mn = min(arr[i] - k, arr[0] + k);
                res = min(res,mx-mn);
            }
        }
        return res;
  }


int main()
{
	fast_io;
	
	int k,n;
	cin >> k >> n;

	int arr[n];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	cout << getMinDiff(arr,n,k) << endl;

	return 0;

}
