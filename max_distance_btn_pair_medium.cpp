/*
You are given two non-increasing 0-indexed integer arrays nums1 and nums2.

A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.

Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.
*/
// O(n) time and O(1) space complexity
//solved by using sliding window method
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i<= nums1.size()-1 and j<=nums2.size()-1) {
            if (nums1[i] > nums2[j] ) {
                i++;
            }else {
                ans = max(ans,j-i);
                j++;
            }
        }
        return ans;
    }
};
