#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

bool possible(bool board[][20],int x, int y, int n){
    //upper column
    for(int k = 0; k <= x; k++){
        if(board[k][y]){
            return false;
        }
    }
    int i = x;
    int j = y;

    //left Diagonal
    while(i >=0 && j >= 0){
        if(board[i][j]){
            return false;
        }
        i--;
        j--;
    }
    i = x;
    j = y;

    //right Diagonal
    while(i >=0 && j < n){
        if(board[i][j]){
            return false;
        }
        i--;
        j++;
    }

    return true;
}

void printBoard(bool board[][20], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";;
        }
        cout << "\n";
    }
}

bool solveNQueen(bool board[][20], int n,int i){
    if(i == n){
        printBoard(board,n);
        return true;
    }

    for(int j=0; j<n; j++){
        if(possible(board,i,j,n)){
            board[i][j] = 1;
            bool success = solveNQueen(board,n,i+1);
            if(success){
                return true;
            }
            board[i][j] = 0;
        }
    }

    return false;

}

int main(){
    fast_io;
    int n;
    cin >> n;

    bool board[20][20] = {0};

    solveNQueen(board,n,0);


    return 0;
}