class Solution {
public:
    void getSubsets(int i,vector<int> &temp, vector<int> &nums, vector<vector<int>> &ans) {
        if(i==nums.size()) {
            ans.push_back(temp);
            return;
        }
        // not taking ith element
        getSubsets(i+1,temp,nums,ans);
        temp.push_back(nums[i]);
        // taking ith element
        getSubsets(i+1,temp,nums,ans);
        temp.pop_back(); //backtracking step undo change
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        getSubsets(0,temp,nums,ans);
        return ans;
    }
};
