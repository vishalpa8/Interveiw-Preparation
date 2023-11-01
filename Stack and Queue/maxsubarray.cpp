// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

// Sliding Window + Dequeue Technie to find the maximum number from contigous array.
vector<int> maxSubarray(vector<int> v, int k,int n){
    // appproach uses dequeue.
    vector<int> ans;   
    deque<int> q;
    int i = 0;

    for(i=0; i<k; i++){
        while(!q.empty() && v[i] > v[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    for(; i<n; i++){
        ans.push_back(v[q.front()]);

        while(!q.empty() && q.front() <= i - k){
            q.pop_back();
        }

        while(!q.empty() && v[i] > v[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    return ans;

}

vector<int> maxSub(vector<int> v, int k, int n){
    vector<int> ans;
    priority_queue<pair<int,int>> pq;
    int i = 0;
    for(i=0; i<k; i++){
        pq.push({v[i],i});
    }

    for(; i<n; i++){
        ans.push_back(pq.top().first);
        while(!pq.empty() && pq.top().second <= i - k){
            pq.pop();
        }
        pq.push({v[i],i});
    }

    return ans;
}

int main(){
    fast_io;
    vector<int> v{1,2,3,1,4,5,2,3,6};

    auto ans = maxSubarray(v,3,v.size());

    for(auto a : ans){
        cout << a << " ";
    }
    cout << "\n";
    ans.clear();

    ans = maxSub(v,3,v.size());

    for(auto a : ans){
        cout << a << " ";
    }


    return 0;
}