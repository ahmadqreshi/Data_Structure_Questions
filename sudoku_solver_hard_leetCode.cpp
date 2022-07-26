/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
*/
class Solution {
public:
    bool canPlace(char ch,vector<vector<char>>& board,int i,int j) {
        for(int k=0;k<9;k++) {
            if(board[i][k]==ch or board[k][j]==ch)
                return false;
        }
        int startRow = (i/3)*3;
        int startCol = (j/3)*3;
        for(int x=0;x<3;x++) {
            for(int y=0;y<3;y++) {
                if(board[x + startRow][y+startCol]==ch)
                    return false;
            }
        }
        return true;
    }
    bool sudokuSolver(vector<vector<char>>& board,int i,int j,int n) {
        if(i==n) {
            return true;
        }
        if(j==n) {
            return sudokuSolver(board,i+1,0,n);
        }
        if(board[i][j]!='.') {
            return sudokuSolver(board,i,j+1,n);
        }
        for(int num = 1 ; num <= n;num++) {
            char ch = num + '0';
            if(canPlace(ch,board,i,j)) {
                board[i][j] = ch;
                bool subProblem = sudokuSolver(board,i,j+1,n);
                if(subProblem)
                    return true;
            }
        }
        board[i][j] = '.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        sudokuSolver(board,0,0,n);
    }
};
