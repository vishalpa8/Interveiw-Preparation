#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

int dp[1001][1001];

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

string printShortestSequence(string s1, string s2, int n, int m){
	int i = n, j = m;
	string s;
	while( i > 0 && j > 0){
		if(s1[i-1] == s2[j-1]){
			s += s1[i-1];
			i--;
			j--;
		}	
		else{
			if(dp[i][j-1] > dp[i-1][j]){
				s += s2[j-1];
				j--;
			}
			else{
				s += s1[i-1];
				i--;
			}
		}
	}
	while( i > 0){
		s += s1[i-1];
		i--;
	}
	while( j > 0){
		s += s2[j-1];
		j--;
	}
	reverse(s.begin(),s.end());
	return s;
}


int main()
{
	fast_io;
	memset(dp,0,sizeof(dp));
	
	cout << lcsTopDownApproach("acbcf","abcdaf",5,6) << endl;
	cout << printShortestSequence("acbcf","abcdaf",5,6) << endl;

	return 0;

}
