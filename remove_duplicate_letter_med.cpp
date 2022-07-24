/*
Given a string s, remove duplicate letters so that every letter appears once and only once.
You must make sure your result is the smallest in lexicographical order among all possible results.
*/
// smallest lexographical meaning from the string only keep those repetation which is more likely to be lexographical and remove other repettion
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mp; // can use also here
        vector<bool> exist(26,false);
        stack<char> st;
        for(char ch : s) {
            mp[ch]++;
        }
        for(int i=0;i<s.size();i++) {
            char ch = s[i];
            mp[ch]--;
            if(exist[ch-'a']) continue;
            while(!st.empty() and st.top() > ch and mp[st.top()] > 0) {
                exist[st.top()-'a'] = false;
                st.pop();
            }
            st.push(ch);
            exist[ch-'a'] = true;
        }
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
