class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {  
        unordered_set<char> row_visited[9];
        unordered_set<char> col_visited[9];
        unordered_set<char> gridVisited[3][3];
        for(int i = 0 ;i < 9;i++) {
            for(int j = 0;j < 9;j++) {
                char gridChar = board[i][j];
                if (gridChar!= '.') {
                    if(row_visited[i].count(gridChar) || col_visited[j].count(gridChar) || gridVisited[i/3][j/3].count(gridChar)) return false;
                    else {
                        row_visited[i].insert(gridChar);
                        col_visited[j].insert(gridChar);
                        gridVisited[i/3][j/3].insert(gridChar);
                    }            
                }
            }
        }
        return true;   
    }
};
