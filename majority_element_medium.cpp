// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        set<int> ans;
        int limit = nums.size()/3;
        unordered_map<int,int> mp;
        for(auto x:nums) {
            mp[x]++;
        }
        for(auto x: nums) {
            if(mp[x]>limit) 
                ans.insert(x);
        }
        vector<int> v(ans.begin(),ans.end()); // convert set to vector
        return v;
    }
};
//method 2 - buyor-moore algorith give it a try
