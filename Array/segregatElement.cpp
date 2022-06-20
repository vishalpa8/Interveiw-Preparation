#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

void solve(){
	int n,m;
	cin >> n >> m;
	int v[n];

	for(int i=0; i<n; i++)
		cin >> v[i];
	
	int ans[n];
	int j = 0;
	for(int i=0; i<n; i++){
		if(v[i] > 0){
			ans[j++] = v[i];
		}
	}
	for(int i=0; i<n; i++){
		if(v[i] < 0){
			ans[j++] = v[i];
		}
	}
	memcpy(v,ans,sizeof(ans));
}


int main(){
	fast_io;

	solve();

	return 0;
}

