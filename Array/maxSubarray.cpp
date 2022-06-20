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
	
	  int ans = -1e9, msf = ans;
        
        for(int i=0; i<n; i++){
            msf = max(msf+arr[i],arr[i]);
            ans = max(ans,msf);
        }
        
        
        return ans;

}


int main(){
	fast_io;

	solve();

	return 0;
}

