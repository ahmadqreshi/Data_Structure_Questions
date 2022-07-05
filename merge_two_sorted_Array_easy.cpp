/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1
*/
// method 1 - o(m+n)-Time and o(m+n)-space complexity
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            ans.push_back(nums2[j]);
            j++;
        }
        for(int i=0;i<ans.size();i++){
            nums1[i]=ans[i];
        }
        
    }
};
// method 2 - o(m+n)-Time and o(1)-space complexity
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 and j>=0) {
            if (nums1[i] < nums2[j]){
                nums1[k] = nums2[j];
                j--;
                k--;
            } else {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
        }
        while(i>=0) {
            nums1[k] = nums1[i];
            i--;
            k--;
        }
        while(j>=0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};
