#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> v(n);

	for(int i=0; i<n; i++){
		cin >> v[i];

	int l = 0, mid = 0, h = n-1;
        
        while(mid <= h){
            switch(a[mid]){
                case 0:
                      swap(a[l++],a[mid++]);
                      break;
                case 1:
                      mid++;
                      break;
                case 2:
                      swap(a[mid],a[h--]);
                      break;
                       
            }
        }
			
}


int main(){
	fast_io;

	solve();

	return 0;
}

