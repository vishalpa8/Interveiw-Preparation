#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

bool compare(pair<int,int> v1, pair<int,int> v2){
    return v1.second < v2.second;
}

int countActivites(vector<pair<int,int>> activities){
    sort(activities.begin(),activities.end(),compare);
    
    int count = 1;
    int second = activities[0].second;

    for(int i=1; i<activities.size(); i++){
        if(activities[i].first >= second){
            count++;
            second = activities[i].second;
        }
    }
    
    return count;
    
}

int main(){
    fast_io;

    vector<pair<int,int>> v{{7,9},{0,10},{4,5},{8,9},{4,10},{5,7}};

    cout << countActivites(v);


    return 0;
}