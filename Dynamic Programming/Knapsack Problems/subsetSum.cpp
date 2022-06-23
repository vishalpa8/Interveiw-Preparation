#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

bool subsetSum(int arr[], int n,int sum){
	bool dp[n+1][sum+1];
	
	for(int i=0; i<n+1; i++){
		for(int j=0; j<sum+1; j++){
			if(i == 0){
				dp[i][j] = false;
			}
			if(j == 0){
				dp[i][j] = true;
			}
		}
	}
	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(arr[i-1] <= sum){
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
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
	int arr[] = {2,3,7,8,10};

	if(subsetSum(arr,5,14)){
		cout << "Sum is present" << endl;
	}
	else
		cout << "Not having any sum Present" << endl;

	return 0;

}
