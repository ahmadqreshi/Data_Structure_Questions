/*
Given an integer array nums and an integer k,
return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k
Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

//approach - we store index of item and item in the map and check if next element is there in map then check i-j<=k 
//if it not then update index of element in the map 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++) {
            if(umap.find(nums[i])!=umap.end()) {
                int diff = abs(i-umap[nums[i]]);
                if(diff<=k) return true;
            }
            umap[nums[i]] = i;
        }
        return false;
    }
};
