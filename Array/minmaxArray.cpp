#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

void solve(){
	int n;
	cin >> n;
	vector<int> v(n);

	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	int mx = INT_MIN, mn = INT_MAX;

	for(auto a : v){
		if(mn > a){
			mn = a;
		}
		if(mx < a){
			mx = a;
		}	
	}
	cout << mn << " " << mx << endl;
}


int main(){
	fast_io;

	solve();

	return 0;
}
