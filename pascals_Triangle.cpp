/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int> helper;
            for(int j = 0 ; j<=i;j++) {
                if(j==0 or i==j) {
                    helper.push_back(1);
                }else {
                    helper.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }
            ans.push_back(helper);
        }
        return ans;
    }
};
