#include<bits/stdc++.h>
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
	
	int last = v[n-1];
	v[n-1] = 0;

	for(int i = n-1; i >= 0; --i){
		v[i] = v[i-1];
	}
	v[0] = last;
	
	for(auto i : v){
		cout << i << " ";
	}

}


int main(){
	fast_io;

	solve();

	return 0;
}
