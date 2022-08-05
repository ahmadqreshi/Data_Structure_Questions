/*
Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
*/
class Solution {
public:
    bool isPalindromic(string str) {
        int s = 0;
        int e = str.size()-1;
        while(s<=e) {
            if(str[s]!=str[e])
                return false;
            else {
                s++;
                e--;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++) {
            if(isPalindromic(words[i])) return words[i];
        }
        return "";
    }
};
