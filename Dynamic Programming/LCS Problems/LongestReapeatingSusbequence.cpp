#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int dp[1001][1001];

int largestRepeatingSubsequence(string s1,string s2, int x, int y){

	for(int i=1; i<x+1; i++){
		for(int j=1; j<y+1; j++){
			if(s1[i-1] == s2[j-1] && i!=j){
				dp[i][j] = 1 + dp[i-1][j-1]; 
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	return dp[x][y];

}

int main()
{
	fast_io;
	memset(dp,0,sizeof(dp));
	
	cout << largestRepeatingSubsequence("aabebcdd","aabebcdd",8,8) << endl;

	return 0;

}
