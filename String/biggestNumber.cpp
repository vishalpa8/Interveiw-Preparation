#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

bool compare(int a, int b){
    string key1 = to_string(a);
    string key2 = to_string(b);
    return key1 + key2 <= key2 + key1;
}

string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string

    sort(numbers.rbegin(),numbers.rend(),compare);
    string ans;

    for(auto number : numbers){
        ans += to_string(number);
    }
    
    return ans;

}

int main(){
    fast_io;

    vector<int> v{10,11,20,30,3};
    cout << concatenate(v);


    return 0;
}