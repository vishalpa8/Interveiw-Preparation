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


int main()
{
	fast_io;
	memset(dp,-1,sizeof(dp));
	
	cout << lcswithoutmemoize(6,6,"vishal","pandey") << endl;
	cout << lcswithmemoize(6,6,"vishal","pandey") << endl;

	return 0;

}
