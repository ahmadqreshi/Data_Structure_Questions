/*
You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
*/
//method 1 - o(n2)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans(r,vector<int>(c,0));
        vector<int> temp;
        int elements = 0;
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[i].size();j++) {
                elements++;
                temp.push_back(mat[i][j]);
            }
        }
        if ((r*c) == elements) {
            int k = 0;
            for(int i=0;i<r;i++) {
                for(int j=0;j<c;j++){
                    ans[i][j] = temp[k++];
                }
            }
        } else {
            return mat;
        }
        
        return ans;
    }
};

//method 2 - o(n) by using ans[i/col][i%col] traverse every element of 2d matrix
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans(r,vector<int>(c,0));
        int row = mat.size();
        int col = mat[0].size();
        if((r*c) != (row*col)) return mat;
        for(int i=0;i<(row*col);i++){
            ans[i/c][i%c] = mat[i/col][i%col];
        }
        return ans;
    }
};
