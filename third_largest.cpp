/*
Given an integer array nums, return the third distinct maximum number in this array.
If the third maximum does not exist, return the maximum number.
*/

//method 1 - by using bruteForce o(n)
class Solution {
public:
    int thirdMax(vector<int>& num) {
        int firstLargest = INT_MIN;
        set<int> nums(num.begin(),num.end());
        for(auto x : nums) {
            firstLargest = max(firstLargest,x);
        }
        if(nums.size() < 3) {
            return firstLargest;
        }
        int secondLargest = INT_MIN;
        for(auto x : nums) {
            if(x > secondLargest and x < firstLargest) {
                secondLargest = x;
            }
        }
        int thirdLargest = INT_MIN;
        for(auto x : nums) {
            if( x < secondLargest and x < firstLargest and x > thirdLargest) {
                thirdLargest = x;
            }
        }
        return thirdLargest;
    }
};


//method 2 - by using sets i.e - storing nums value in descending order in set
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int,greater<int>> ans(nums.begin(),nums.end());
        if(ans.size() < 3) {
            return *ans.begin();
        }
        int count = 1 ;
        int temp;
        for(auto x : ans) {
            if(count==3) {
                temp = x;
                break;
            }
            count++;
        }
        return temp;
          
    }
};

//method 3 - by finding top three element
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long firstLargest = LONG_MIN; //we using long min here because nums[i] can be 2^31
        long secondLargest = LONG_MIN;
        long thirdLargest = LONG_MIN;
        for(auto val : nums) {
            if(val > firstLargest) {
                thirdLargest = secondLargest;
                secondLargest = firstLargest;
                firstLargest = val;
            } else if(val > secondLargest and val < firstLargest) {
                thirdLargest = secondLargest;
                secondLargest = val;
            } else if(val > thirdLargest and val < secondLargest) {
                thirdLargest = val;
            }
        }
        if(thirdLargest == LONG_MIN) { // size less than 3
            return firstLargest;
        } else {
            return thirdLargest;
        }
          
    }
};
