#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

string isSubset(int a1[], int a2[], int n, int m) {
    set<int> s;
    
    for(int i=0; i<n; i++){
        s.insert(a1[i]);
    }
    
    for(int i=0; i<m; i++){
        if(s.find(a2[i]) == s.end()){
            return "No";
        }
    }
    
    return "Yes";
}
int main()
{
	fast_io;
	int A[] = {1,2,3,-2,5};
	int B[] = {1,-1,5};

	cout << isSubset(A,B,5,3) << endl;


	return 0;

}
