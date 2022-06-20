#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> v(n),a(n);
	set<int> s;

	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	for(int i=0; i<m; i++){
		cin >> a[i];
	}
	for(int i=0; i<n; i++){
		s.insert(v[i]);
	}	
	for(int i=0; i<m; i++){
		s.insert(a[i]);
	}
	cout << s.size() << endl;

}


int main(){
	fast_io;

	solve();

	return 0;
}
