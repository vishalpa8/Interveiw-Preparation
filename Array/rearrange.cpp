#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
void rearrange(int arr[], int n3) {
	vector<int> p,n;


	for(int i=0; i<n3; i++){
		if(arr[i] >= 0){
			p.push_back(arr[i]);
		}
		else{
			n.push_back(arr[i]);
		}
	}
	int i = 0;
	int n1 = p.size(), n2 = n.size();
	int c1 = 0, c2 = 0;

	while(i < n3){
		if(c1 < n1){
			arr[i++] = p[c1++];
		}
		if(c2 < n2){
			arr[i++] = n[c2++];
		}
	}	 
  	for(int i=0; i<n3; i++){
		cout << arr[i] << " ";
	}	
}
int main(){
	fast_io;
	int A[] = {1,2,3,-2,5};

	rearrange(A,5);


	return 0;

}
