#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
bool isPalindrome(string s, int i, int j){
	if(i > j){
		return false;
	}
	if( i == j){
		return true;
	}
	while( i < j){
		
		if(s[i] != s[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int dp[105][105];
int solve(string arr, int i, int j){
    if(i >= j) return 0;

	if(isPalindrome(arr,i,j)) return 0;
        
     int mn = INT_MAX;
        
     if(dp[i][j] != -1){ 
         return dp[i][j];
	 }
        
     for(int k = i; k <= j-1; k++){
		 int left, right;
		 if(dp[i][k] != -1){
			 left = dp[i][k];
		 }
		 else{
			 left = solve(arr,i,k);
			 dp[i][k] = left;
		 }
		 if(dp[k+1][j] != -1){
			 right = dp[k+1][j];
		 }
		 else{
			 right = solve(arr,k+1,j);
			 dp[k+1][j] = right;
		 }

         int temp = left + right + 1;
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
	string s = "ababbbabbababa";	

	cout << solve(s,0,s.length()-1) << endl;

	return 0;

}
