#include <iostream>
using namespace std;
void print(int sudoku[][9],int n) {
    int k=0;
    for(int i=0;i< n*n ;i++){
        cout<<sudoku[i/n][i%n]<<" ";
        k++;
        if(k==9) cout<<endl,k=0;
    }
}
bool canPlace(int sudoku[][9],int i,int j,int no) {
    for(int k=0;k<9;k++) { // checks whether no can be placed in row and column
        if(sudoku[i][k]==no)
        return false;
    }
    for(int k=0;k<9;k++) { // checks whether no can be placed in row and column
        if(sudoku[k][j]==no)
        return false;
    }
    int sx = (i/3)*3; // for now assume sudoko to be 9*9
    int sy = (j/3)*3;
    for(int x = 0; x < 3; x++) { // checks whether no can be placed in the 3*3 subgrid
        for(int y = 0; y < 3;y++) {
            if(sudoku[x+sx][y+sy]==no)
             return false;
        }
    }
    return true;
}
bool isSafe(int sudoku[][9], int i,int j, int no)
{

    for (int x = 0; x < 9; x++)
        if (sudoku[i][x] == no or sudoku[x][j] == no)
            return false;
 
    int startRow = (i/3)*3;
    int startCol = (j/3)*3;
    // int startRow = row - row % 3;
    // int startCol = col - col % 3;
    for (int x = startRow; x < startRow+3; x++)
        for (int y = startCol; y <startCol+3; y++)
            if (sudoku[x][y] == no)
                return false;
 
    return true;
}
bool sudokuSolver(int sudoku[][9],int i,int j,int n) {
    //base case
    // validates row
    if(i==n) {
        //print Solution
        print(sudoku,n);
        return true;
    }
    //validates column
    if(j==n) {
        return sudokuSolver(sudoku,i+1,0,n);
    }
    //validates prefilled cells
    if(sudoku[i][j]!=0) {
        return sudokuSolver(sudoku,i,j+1,n);
    }
    //recursive condition
    for(int no = 1 ; no <= n;no++) {
        if(canPlace(sudoku,i,j,no)) {
            sudoku[i][j] = no;
            bool remainingSolution = sudokuSolver(sudoku,i,j+1,n);
            if(remainingSolution==true) {
                return true;
            }
        }
    }
    //if no value for current index found
    sudoku[i][j] = 0; // backtracking step 
    return false;
}
int main()
{
    int sudoku[9][9] = { 
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    bool ans = sudokuSolver(sudoku,0,0,9);
    if(!ans) cout<<"Solution not possible"<<endl;
    // print(sudoku,9);
    return 0;
}
//OUTPUT
/*
5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9 
*/
