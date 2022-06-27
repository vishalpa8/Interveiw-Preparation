#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int dp[1001][1001];

int minDeletionPalidromeSequence(string s1, int x){
	string s2 = s1;
	reverse(s2.begin(),s2.end());
	for(int i=1; i<x+1; i++){
		for(int j=1; j<x+1; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1]; 
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return x - dp[x][x];	
}



int main()
{
	fast_io;
	memset(dp,0,sizeof(dp));
	
	cout << minDeletionPalidromeSequence("agbcba",6) << endl;

	return 0;

}
