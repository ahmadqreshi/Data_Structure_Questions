/*
      Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.
*/

//method 1 - naive approach
class Solution {
public:
    int fetchSum(int i,int j,vector<vector<int>>& mat,int m,int n,int k) {
        int sum = 0;
        for(int r = i-k ; r<=i+k;r++) {
            if(r>=0 and r<m) {
                for(int c = j-k;c<=j+k;c++) {
                    if(c>=0 and c <n) {
                        sum += mat[r][c];
                    }
                }
            }
        }
        return sum;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m*n;i++) {
            ans[i/n][i%n] = fetchSum(i/n,i%n,mat,m,n,k); // fetch calculates r, c from mat and then add their sum
        }
        return ans;
    }
};
//method 2 - by using dp commulative sum
