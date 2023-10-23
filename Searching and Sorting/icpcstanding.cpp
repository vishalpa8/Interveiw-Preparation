#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

bool compare(pair<string,int> x, pair<string,int> y){
    return x.second < y.second;
}

int badass(vector<pair<string,int>> teams){
    // sort(teams.begin(),teams.end(),compare);
    int ans = 0;
    for(int i = 0; i < teams.size(); i++){
        ans ^= teams[i].second;
    }
    return ans;

}

int main(){
    fast_io;
    vector<pair<string,int>> teams
    {{"WinOrBooze",1},{"BallOfDuty",2},
    { "WhoKnows",2},{"BholeChature",1 },
    {"DCECoders",5 },{"StrangeCase",7},
    {"WhoKnows",7}};

    int ans = badass(teams);
    cout<<ans<<endl;

    return 0;
}