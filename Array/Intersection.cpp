#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

vector<int>commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
   	int i=0,j=0,k=0;
    vector<int> v;
      while(i<n1 && j<n2 && k<n3){
            if(i<n1 && A[i] == A[i+1])
              i++;
			if(j<n2 && B[j] == B[j+1])
			 	j++;
			if(k<n3 && C[k] == C[k+1])
				k++;
			else if((A[i] == B[j]) && (B[j] == C[k])){
					v.push_back(A[i]);
					i++;j++;k++;
				}
			else{
					int m=max({A[i],B[j],C[k]});
					if(A[i]<m)
							i++;
					if(B[j]<m)
							j++;
					if(C[k]<m)
							k++;
			}
	  }
	  return v;
}


int main()
{
	fast_io;
	int A[] = {1, 5, 10, 20, 40, 80};
	int n2 = 5,n1 = 6; 
	int B[] = {6, 7, 20, 80, 100};;
	int n3 = 8; 
	int C[] = {3, 4, 15, 20, 30, 70, 80, 120};

	vector<int> v = commonElements(A,B,C,n1,n2,n3);

	for(auto i : v){
		cout << i << " ";
	}
	cout << endl;;
	return 0;

}
