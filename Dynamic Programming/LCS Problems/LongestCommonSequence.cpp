#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int dp[1001][1001];

int lcswithoutmemoize(int x, int y, string s1, string s2){

    if(x == 0 || y == 0){
         return 0;
    }
        
    if(s1[x-1] == s2[y-1]){
		return 1 + lcswithoutmemoize(x-1,y-1,s1,s2);
	}
 	return max(lcswithoutmemoize(x-1,y,s1,s2),lcswithoutmemoize(x,y-1,s1,s2));
}
int lcswithmemoize(int x, int y, string s1, string s2){

    if(x == 0 || y == 0){
         return 0;
    }
	if(dp[x][y] != -1){
		return dp[x][y];
	}
        
    if(s1[x-1] == s2[y-1]){
		dp[x][y] = 1 + lcswithmemoize(x-1,y-1,s1,s2);
	}
	else
		dp[x][y] = max(lcswithmemoize(x-1,y,s1,s2),lcswithmemoize(x,y-1,s1,s2));

	return dp[x][y];
}
int lcsTopDownApproach(string s1,string s2, int x, int y){

	for(int i=1; i<x+1; i++){
		for(int j=1; j<y+1; j++){
			if(s1[i-1] == s2[j-1]){
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
	
	cout << lcswithoutmemoize(6,6,"vishal","pandey") << endl;
	cout << lcswithmemoize(6,6,"vishal","pandey") << endl;
	cout << lcsTopDownApproach("vishal","pandey",6,6) << endl;


	return 0;

}
