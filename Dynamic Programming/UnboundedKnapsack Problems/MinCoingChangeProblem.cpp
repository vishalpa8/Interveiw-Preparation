#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int minCoinChangeProblem(int arr[], int n,int sum){
	int dp[n+1][sum+1];

	for(int i=0; i<n+1; i++){
		for(int j=0; j<sum+1; j++){
			if( i == 0){
				dp[i][j] = INT_MAX-1;
			}
			if( j == 0){
				dp[i][j] = 0;
			}
			if( i == 1 && j > 0){
				if( j % arr[0] == 0){
					dp[i][j] = j/arr[0];
				}
				else
					dp[i][j] = INT_MAX-1;
			}
		}
	}
	for(int i=1; i<sum+1; i++){

	}
	for(int i=2; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(arr[i-1] <= j){
				dp[i][j] = min(1 + dp[i][j-arr[i-1]], dp[i-1][j]);
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][sum];
}


int main()
{
	fast_io;
	int arr[] = {1,2,3};

	cout << minCoinChangeProblem(arr,3,5) << endl;
	
	
	return 0;

}
