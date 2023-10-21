#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
vector<vector<int>> findTripletNumbers(vector<int>&v, int target){
		int n = v.size();
		vector<vector<int>>ans;
		sort(v.begin(),v.end());

		for(int i=0; i<n; i++){
			int val = target - v[i];
			int j = i+1, k = n-1;
			while(j < k){
				int sum = v[j] + v[k];
				if(sum == val){
					ans.push_back({v[i],v[j],v[k]});
					j++;
					k--;
				}
				else if(sum > val){
					k--;
				}
				else{
					j++;
				}
			}
		}

		return ans;

}


int main(){
	// fast_io;
	vector<int> v{1,2,4,6,3,5,7,9,8,15};
	int target = 18;

	auto ans = findTripletNumbers(v,target);

	for(auto a : ans){
		for(auto p : a){
			cout << p << " ";
		}
		cout << "\n";
	}


	return 0;

}
