#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
int solve(int arr[], int n){
	int ans = 0, count = 0;

	for(int i=0; i<n; i++){
		if(arr[i]+1 == arr[i+1]{
			count++;
		}
		else if(arr[i+1] != arr[i] && arr[i]+1 != arr[i+1]){
			count = 0;
		}
		ans = max(count, ans);
	}

	return ans+1;

}

int main()
{
	fast_io;
	int A[] = {1,2,3,-2,5};

	cout << solve(A,5) << endl;


	return 0;

}
