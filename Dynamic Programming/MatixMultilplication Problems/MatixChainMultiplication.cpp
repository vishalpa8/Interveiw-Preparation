#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int minMatrixMutliplication(int arr[], int i, int j){
	if( i >= j){
		return 0;
	}
	int mn = INT_MAX;
	for(int k = i; k < j; k++){
		int temp = minMatrixMutliplication(arr,i,k) + minMatrixMutliplication(arr,k+1,j) + (arr[i-1] * arr[j] * arr[k]);

		if(temp < mn){
			mn = temp;
		}
	}
	return mn;
}

int dp[105][105];
int solve(int arr[], int i, int j){
    if(i >= j) return 0;
        
     int mn = INT_MAX;
        
     if(dp[i][j] != -1){
         return dp[i][j];
	 }
        
     for(int k = i; k < j; k++){
         int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1] * arr[j] * arr[k];
           if(temp < mn){
               mn = temp;
           }
       }
       dp[i][j] = mn;
       return mn;
}

int main()
{
	fast_io;
	memset(dp,-1,sizeof(dp));
	int arr[] = {10,20,30,40,30};	
	cout << minMatrixMutliplication(arr,1,4) << endl;
	cout << solve(arr,1,4) << endl;

	return 0;

}
