/*
Example 1:
3 2 1
1 7 6
2 7 7 
Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
*/

//method 1 o(n3) - bruteForce
class Solution {
public:
    bool isEqual(vector<int> &a, vector<int> &b) {
        for(int i=0;i<a.size();i++) {
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> columns;
        for(int i=0;i<n;i++) {
            vector<int> temp;
            for(int j=0;j<n;j++) {
                temp.push_back(grid[j][i]);
            }
            columns.push_back(temp);
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(isEqual(grid[i],columns[j])) {
                    ans++;
                }
            }
        }
        return ans;
    }
};


//method 2 o(n2) by using map of column vector
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> umap;
        int n = grid.size();
        for(int i=0;i<n;i++) {
            vector<int> temp;
            for(int j=0;j<n;j++) {
                temp.push_back(grid[j][i]);
            }
            umap[temp]++;
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(umap.find(grid[i])!=umap.end()) ans += umap[grid[i]];
        }
        return ans;
    }
};
