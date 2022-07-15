/*
There is a function signFunc(x) that returns:
1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.
Return signFunc(product).
*/
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;
        for(auto x:nums) {
            if(x<0) count++;
            else if(x==0) return 0;
        }
        if(!(count&1)) return 1; // checks whether the count of negative numbers are equal or not if equal their product will be positive
        return -1;
    }
};
