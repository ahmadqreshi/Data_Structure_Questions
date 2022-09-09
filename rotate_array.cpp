//method 1 - by using while and for loop
//Time Complexity - O(n*d)
//Space Complexity - O(1)

//method 2 - by using modulo operator
//Time Complexity - O(n)
//Space Complexity - O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,0);
        int left = 0;
        int right = n-1;
        for(int i = k%n - 1;i>=0;i--) {
            ans[i] = nums[right--];
        }
        for(int i=k%n;i<n;i++) {
            ans[i] = nums[left++];
        }
        nums = ans;
    }
};
//method 2 - by using modulo operator and some logic
//Time Complexity - O(n)
//Space Complexity - O(1)
class Solution {
public:
    void rev(vector<int> &arr,int s,int e) {
        while(s<e) {
            swap(arr[s++],arr[e--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int pos = k%nums.size();
        rev(nums,0,nums.size()-1);
        rev(nums,0,pos-1);
        rev(nums,pos,nums.size()-1);
    }
};
