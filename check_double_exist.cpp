/*
Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).
More formally check if there exists two indices i and j such that :
i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
*/
//method 1 - brute force O (n2)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i=0;i<arr.size();i++) {
            for(int j = 0;j<arr.size();j++) {
                if(arr[i] == 2*arr[j])
                    return true;
            }
        }
        return false;
    }
};
//method 2 - by using binary search O (nlogn)
class Solution {
public:
    int check(vector<int> &arr,int key) {
        int s=0;
        int e=arr.size()-1;
        while(s<=e) {
            int mid = (s + e)/2;
            if(arr[mid]==key)
                return mid;
            else if(arr[mid]<key) {
                s = mid + 1;
            }else {
                e = mid-1;
            }
        }
        return -1;
    }
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++) {
            int help = check(arr,2*arr[i]);
            if(help!=-1 and help!=i)
                return true;  
        }
        return false;
    }
};
