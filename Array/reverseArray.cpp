#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

void solve(){
	int n;
	cin >> n;
	vector<int> v(n);

	for(int i=0; i<n; ++i){
		cin >> v[i];
	}

	int j = 0, k = n-1;

	while(j < k){
		swap(v[j++],v[k--]);
	}

	for(auto i : v){
		cout << i << " ";
	}
	cout << endl;
}


int main()
{
	fast_io;
	
	int n;
	cin >> n;

	while(n--){
		solve();
	}


	return 0;

}
