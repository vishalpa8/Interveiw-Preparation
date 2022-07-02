#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
int getPairsCount(int arr[], int n, int k) {
	unordered_map<int,int> mp;
	int count = 0;

	for(int i=0; i<n; i++){
		int target = k - arr[i];
		if(mp[target] != 0){
			count +=  mp[target];
		}
		mp[arr[i]]++;
	}           
	return count;

}

int main(){
	fast_io;
	int A[] = {1,2,3,-2,5};

	cout << getPairsCount(A,5,6) << endl;


	return 0;

}
