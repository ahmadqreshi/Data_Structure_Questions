#include <bits/stdc++.h>
using namespace std;
int solutionExist = 0;
void print(vector<vector<char>> &board,int n) {
    int k = 0;
    for(int i=0;i< n*n; i++) {
        cout<<board[i/n][i%n]<<" ";
        k++;
        if(k==n) cout<<endl,k=0;
    }
}
bool canPlace(vector<vector<char>> &board,int i,int j,int n) {
    for(int k=0;k<i;k++) {
        if(board[k][j]=='Q')
            return false;
    }
    int x = i;
    int y = j;
    while(x>=0 and y >=0) {
        if(board[x][y] == 'Q')
            return false;
        x--;
        y--;
    }
    x = i;
    y = j;
    while(x>=0 and y<n) {
        if(board[x][y] == 'Q')
            return false;
        x--;
        y++;
    }
    return true;
}
int nQueenSolver(vector<vector<char>> &board,int i,int n) {
    if(i==n){
        // print(board,n);
        // cout<<endl;
        return 1;
    }
    for(int j=0 ; j<n ; j++) {
        if(canPlace(board,i,j,n)) {
            board[i][j] = 'Q';
            solutionExist += nQueenSolver(board,i+1,n);
            board[i][j] = '.';
        }
    }
    return 0;
}
int main()
{
    int n = 4;
    vector<vector<char>> board(n,vector<char>(n,'.'));
    nQueenSolver(board,0,n);
    cout<<solutionExist;
    return 0;
}
//OUPUT for n = 4 
//2
