#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
int solve(int arr[], int n){
	int ans = arr[0], msf = ans;

	for(int i=1; i<n; i++){
		ans = max(arr[i] + ans,arr[i]);
		msf = max(msf,ans);
	}
	return msf;
}

int main()
{
	fast_io;
	int A[] = {1,2,3,-2,5};

	cout << solve(A,5) << endl;


	return 0;

}
