#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int t[100][1002];


int KnapsackWithoutMemoize(int wt[],int val[],int W, int n){
	if(W == 0 || n == 0){
		return 0;
	}
	
	if(wt[n-1] <= W){
		return max(val[n-1] + KnapsackWithoutMemoize(wt,val,W-wt[n-1],n-1),KnapsackWithoutMemoize(wt,val,W,n-1));
	}

	return KnapsackWithoutMemoize(wt,val,W,n-1);
	

}

int KnapsackWithMemoize(int wt[],int val[],int W, int n){

	if(W == 0 || n == 0){
		return 0;
	}

	if(t[n][W] != -1){
		return t[n][W];
	}
	
	if(wt[n-1] <= W){
		t[n][W] = max(val[n-1] + KnapsackWithoutMemoize(wt,val,W-wt[n-1],n-1),KnapsackWithoutMemoize(wt,val,W,n-1));
	}
	else 
		t[n][W] = KnapsackWithoutMemoize(wt,val,W,n-1);

	return t[n][W];
	
}

int topDownApproach(int wt[],int val[],int W, int n){ 
	int dp[n+1][W+1];
	memset(dp,0,sizeof(dp));

	for(int i=1; i<n+1; i++){
		for(int j=1; j<W+1; j++){
			if(wt[i-1] <= W){
				dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][W];

	
}

int main()
{
	fast_io;
	memset(t,-1,sizeof(t));
	int wt[] = {10,20,30};
   	int val[] = {60,100,120};	

	cout << KnapsackWithoutMemoize(wt,val,50,3) << endl;

	cout << KnapsackWithMemoize(wt,val,50,3) << endl;

	cout << topDownApproach(wt,val,50,3) << endl;

	return 0;

}
