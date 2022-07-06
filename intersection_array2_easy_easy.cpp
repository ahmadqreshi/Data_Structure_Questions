/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
*/
//method 1 - sorting and two pointer technique
//time complexity - o(nlogn)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<nums1.size() and j<nums2.size()) {
            if(nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i]<nums2[j]) {
                i++;
            }else {
                j++;
            }
        }
        return ans;
    }
};

//method 2 - using hashmap or unordered map in c++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto x:nums1){
            mp[x]++;
        }
        for(auto x : nums2) {
            if(mp[x]>0) {
                ans.push_back(x);
                mp[x]--;
            }
        }
        return ans;
    }
};
