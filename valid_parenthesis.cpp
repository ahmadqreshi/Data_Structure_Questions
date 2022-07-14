class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        char ch;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='[' or s[i]=='{' or s[i] == '('){
                st.push(s[i]);
                continue;
            }
            if(st.empty()) // check empty because ")" only it will show run time error
                return false;
            switch(s[i]) {
                case ']' :
                    ch = st.top();
                    st.pop();
                    if(ch == '(' or ch == '{')
                        return false;
                    break;
                case '}' :
                    ch = st.top();
                    st.pop();
                    if(ch == '(' or ch == '[')
                        return false;
                    break;
                case ')' :
                    ch = st.top();
                    st.pop();
                    if(ch == '[' or ch == '{')
                        return false;
                    break;
            }
        }
        return st.empty();
    }
};
