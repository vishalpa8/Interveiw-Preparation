#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

bool possible(int mat[][9],int i, int j, int no, int n){

    for(int k=0; k<n; k++){
        if(mat[i][k] == no || mat[k][j] == no){
            return false;
        }        
    } 

    int x = (i / 3) * 3;
    int y = (j / 3) * 3;
    // // i = 8 and  j = 1   i = 6, j = 0   8/3=>2*3 = 6, 1/3 => 0
    for(int p = x; p < x + 3; p++){
        for(int q = y; q < y + 3; q++){
            if(mat[p][q] == no){
                return false;
            }
        }
    }

    return true;
}

void printBoard(int mat[][9], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

bool solveSudoku(int mat[][9], int i, int j, int n){
    if(i == n){
        printBoard(mat,n);
        return true;
    }
    if(j == n){
        return solveSudoku(mat,i+1,0,n);
    }

    if(mat[i][j] != 0){
        return solveSudoku(mat,i,j+1,n);
    }

    for(int no = 1; no <= n; no++){
        if(possible(mat,i,j,no,n)){
            mat[i][j] = no;
            bool solveProblem = solveSudoku(mat,i,j+1,n);

            if(solveProblem){
                return true;
            }
        }
    }


    mat[i][j] = 0;
    return false;
}

int main(){
    fast_io;

    int n = 9;
	int mat[9][9] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},    
        {0,0,0,0,8,0,0,7,9}};
    

        if(!solveSudoku(mat,0,0,n)){
            cout << "No Solution Found";
        }

    return 0;
}