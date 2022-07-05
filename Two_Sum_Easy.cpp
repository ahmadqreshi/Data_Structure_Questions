//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//method 1 - o(n2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0 ;i<nums.size()-1;i++) {
            for(int j = i+1;j<nums.size();j++){
                if((nums[i] + nums[j]) == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};
//method 2 - o(n) by using unordered map whose searching comp. is o(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++) {
            int j = target - nums[i]; // second element to find
            if (umap.find(j) != umap.end()) {
                return {i,umap[j]};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};
// or 
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> imap;
    
    for (int i = 0;; ++i) {
        auto it = imap.find(target - nums[i]);
        
        if (it != imap.end()) 
            return vector<int> {i, it->second};
            
        imap[nums[i]] = i;
    }
}
