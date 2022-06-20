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
		
	priority_queue<int>maxh;
      for(int i=l;i<=r;i++)
       {
           maxh.push(arr[i]);
           if(maxh.size()>k)
           {
               maxh.pop();
           }
       }
      return maxh.top();
	
}


int main(){
	fast_io;

	solve();

	return 0;
}
