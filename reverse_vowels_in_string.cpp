class Solution {
public:
    bool checkVowel(char ch) {
        if(ch=='a' or ch=='A'){
            return true;
        }else if(ch=='e' or ch=='E') {
            return true;
        }else if(ch=='i' or ch=='I') {
            return true;
        }else if(ch=='o' or ch=='O') {
            return true;
        }else if(ch=='u' or ch=='U') {
            return true;
        }else
            return false;
    }
    string reverseVowels(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start<=end) {
           if (checkVowel(s[start])) {
               if (checkVowel(s[end])) {
                   swap(s[start],s[end]);
                   start++;
                   end--;
               }else{
                   end--;
               }
           }else{
               start++;
           }
        }
        return s;
    }
};
