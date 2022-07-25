/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
*/
class Solution {
public:
    bool canPlace(vector<vector<char>> &board,int n,int x,int y) {
        for(int k=0;k<x;k++) { // checks the column
            if(board[k][y] == 'Q')
                return false;
        }
        int i=x;
        int j=y;
        while(i>=0 and j>=0) { // checks dioganal of first half
            if(board[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        i = x;
        j = y;
        while(i>=0 and j<n){ // checks diagonal of second half
            if(board[i][j]=='Q')
                return false;
            i--;
            j++;
        }
        return true;
    }
    void addElement(vector<vector<string>> &ans,vector<vector<char>> &board,int n){
        vector<string> temp;
        for(int i = 0;i<n;i++){
            string tempStr = "";
            for(int j=0;j<n;j++)
                tempStr += board[i][j];
            temp.push_back(tempStr);
        }
        ans.push_back(temp);
    }
    void solveProblem(vector<vector<string>> &ans,int n,vector<vector<char>> &board,int i) {
        if(i==n) {
            addElement(ans,board,n);
            return;
        }
        for(int j=0;j<n;j++) {
            if(canPlace(board,n,i,j)) {
                board[i][j] = 'Q';
                solveProblem(ans,n,board,i+1);
                board[i][j] = '.'; //backTracking step - undo change if found solution to find another solution
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n,vector<char>(n,'.'));
        solveProblem(ans,n,board,0);
        return ans;
    }
};
