#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int rodCuttingProblem(int arr[], int n){
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	
	vector<int> v;
	for(int i=0; i<n; i++){
		v.push_back(i+1);
	}

	for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++){
			if(v[i-1] <= j){
				dp[i][j] = max(arr[i-1] + dp[i][j-v[i-1]],dp[i-1][j]);
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][n];
}


int main()
{
	fast_io;
	int arr[] = {1,5,8,9,10,17,17,20};

	cout << rodCuttingProblem(arr,8) << endl;
	
	
	return 0;

}
