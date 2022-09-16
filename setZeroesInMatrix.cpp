//method 1 - brute force o(n*m)2
//step 1 - if matrix element is zero then fill that row and col values to -1
//step 2 - after doing this we can set those values to zero
#include <bits/stdc++.h> 
void setValue(vector<vector<int>> &matrix,int row,int col) {
    for(int i=0;i<matrix.size();i++) {
        for(int j=0;j<matrix[i].size();j++) {
            if((i==row or j == col) and matrix[i][j]!=0) {
                matrix[i][j] = -1;
            }
        }
    }
}
void setZeros(vector<vector<int>> &matrix)
{
    for(int i=0;i<matrix.size();i++) {
        for(int j=0;j<matrix[i].size();j++) {
            if(matrix[i][j]==0) {
                setValue(matrix,i,j);
            }
        }
    }
    for(int i=0;i<matrix.size();i++) {
        for(int j=0;j<matrix[0].size();j++) {
            if(matrix[i][j]==-1) {
                matrix[i][j] = 0;
            }
        }
    }
}

//method 2 - by using row 0 and col 0 as dummy arrays and set data inside matrix according to that data
#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
    int col0 = 1,row = matrix.size(),col=matrix[0].size();
    for(int i=0;i<row;i++) {
        if(matrix[i][0]==0) col0 = 0;
        for(int j=1;j<col;j++) {
            if(matrix[i][j]==0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for(int i=row-1;i>=0;i--) {
        for(int j=col-1;j>=1;j--) {
            if(matrix[i][0]==0 or matrix[0][j]==0) {
                matrix[i][j] = 0;
            }
        }
        if(col0==0) matrix[i][0] = 0;
    }
}
