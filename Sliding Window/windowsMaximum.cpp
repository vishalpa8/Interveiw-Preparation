#include<bits/stdc++.h>
using namespace std;


vector<int> maxInWindow(vector<int> v,int target){
    int n = v.size();
		vector<int>ans;
		sort(v.begin(),v.end());

		for(int i=0; i<n; i++){
			int val = target - v[i];
			int j = i+1, k = n-1;
			while(j < k){
				int sum = v[j] + v[k];
				if(sum == val){
					int value = max(v[i],v[j]);
                    v.push_back(max(value,v[k]));
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

    return v;
    
}

int main(){
    vector<int> v{1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;

    auto ans = maxInWindow(v,k);

    for(auto a : ans){
        cout << a << " ";
    }


    return 0;
}