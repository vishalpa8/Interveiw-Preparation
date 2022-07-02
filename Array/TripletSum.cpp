#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
bool find3Numbers(int A[], int n, int X)
{
	set<int> s;
       
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int target = X - A[i] - A[j];
				if(s.find(target) != s.end()){
					return 1;
				}
		}
		s.insert(A[i]);
	}
	return 0;
}


int main(){
	fast_io;
	int A[] = {1,2,3,-2,5};

	cout << find3Numbers(A,5,6) << endl;


	return 0;

}
