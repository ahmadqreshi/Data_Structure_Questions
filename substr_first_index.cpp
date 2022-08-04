/*
Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

//method 1 o(n2) n - size of haystack

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++) {
            string temp = "";
            for(int j=i;j<haystack.size();j++) {
                temp += haystack[j];
                if(temp==needle) return i;
            }
        }
        return -1;
    }
};

//method 2 o(n*m) - time complexity of substr is o(m) where m is the size of substring
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i=0;i<n;i++) {
            string temp = haystack.substr(i,m);
            if(temp==needle) return i;
        }
        return -1;
    }
};
