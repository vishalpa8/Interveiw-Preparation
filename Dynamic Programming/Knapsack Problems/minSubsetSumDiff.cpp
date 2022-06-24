#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

vector<int> subsetSum(int arr[], int n,int sum){
	bool dp[n+1][sum+1];
	vector<int> ans;
	
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

	for(int i=0; i<(sum+1)/2; i++){
		if(dp[n][i]){
			ans.push_back(i);
		}
	}

	return ans;
}

int minSubsetSumDiff(int arr[], int n){
	int range = 0;

	for(int i=0; i<n; i++){
		range +=  arr[i];
	}
	vector<int> v = subsetSum(arr,n,range);

	int mn = INT_MAX;

	for(auto i : v){
		mn = min(mn,range - (2 * i));
	}

	return mn;
}



int main()
{
	fast_io;
	int arr[] = {1,6,11,5};

	cout << minSubsetSumDiff(arr,4) << endl;
	
	
	return 0;

}
