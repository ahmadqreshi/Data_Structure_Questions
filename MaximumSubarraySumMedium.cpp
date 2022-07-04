// this question is solved by using kadanes algorithm in o(n)
// current sum will be checked after adding current value because an array can also have negative values only
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int curSum = 0;
        for(int i=0;i<nums.size();i++) {
            curSum += nums[i];
            maxSum = max(maxSum,curSum);
            if(curSum < 0) {
                curSum = 0;
            }
        }
        return maxSum;
    }
};
