/*
You are given an array people where people[i] is the weight of the ith person, 
and an infinite number of boats where each boat can carry a maximum weight of limit. 
Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
Return the minimum number of boats to carry every given person.
*/

//method 1 - by using two pointer greedy approach
class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(arr.begin(),arr.end());
        int count = 0;
        int i = 0;
        int j = arr.size()-1;
        while(i<=j) {
            count++;
            if(arr[i]+arr[j] <= limit) {
                i++;
            }   
            j--;
        }
        return count;
    }
};
//method 2  by using simple thinking 
class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(arr.begin(),arr.end());
        int count = 0;
        int i = 0;
        int j = arr.size()-1;
        while(i<=j) {
            int sum = arr[i] + arr[j];
            if(sum < limit) { // here both person will go in one boat 
                count++;
                i++;
                j--;
            }else if(sum > limit) {// here also one person will go who is heaviest
                count++;
                j--;
            }else { // here both person will go because their weights are equal
                count++;
                i++;
                j--;
            }
        }
        return count;
    }
};
