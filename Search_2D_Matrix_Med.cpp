class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowTraverse = 0;
        int colTraverse = matrix[0].size()-1;
        while(rowTraverse < matrix.size() and colTraverse>=0) {
            if(matrix[rowTraverse][colTraverse] == target) return true;
            else if(target < matrix[rowTraverse][colTraverse]){
                colTraverse--;
            }else {
                rowTraverse++;
            }
        }
        return false;
    }
};
