#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

bool canPlaceBirds(vector<int> nests, int n, int sep, int birds){
    int bird = 1;
    int location = nests[0];

    for(int i=1; i<=n-1; i++){
        int current_location = nests[i];

        if(current_location - location >= sep){
            bird++;
            location = current_location;

            if(bird == birds){
                return true;
            }
        }
    }

    return false;
}

int angryBird(vector<int> v, int n,int B){
    sort(v.begin(),v.end());
    int s = 0;
    int e = v[n-1] - v[0];
    int ans = -1;

    while(s <= e){
        int mid = (s + e)/2;
        bool place = canPlaceBirds(v,n,mid,B);
        
        if(place){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }

    return ans;
}

int main(){
    fast_io;

    vector<int> nests{1,2,4,8,9};
    int bird = 3;

    cout << angryBird(nests,nests.size(),bird) << "\n";


    return 0;
}