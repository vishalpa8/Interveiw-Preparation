#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

vector<int> sortBalls(vector<int> balls){
    //sort the balls in place in a single pass (O(N) time, O(1) space)
    
    int mid = 0 ,i = 0, j = balls.size()-1;

    while(mid <= j){
        switch(balls[mid]){
            case 0:
                swap(balls[i++],balls[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(balls[mid],balls[j--]);
                break;
        }
    }
        
    
    return balls;
}

int main(){
    fast_io;




    return 0;
}