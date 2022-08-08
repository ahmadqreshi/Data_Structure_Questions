// make both string equal by adding zero
// now initialize carry with zero
// and now simple binary addition
// after this add carry if it is 1
// now add helper vector elements in reverse in the final answer
class Solution {
public:
    string addBinary(string a, string b) {
        vector<char> helper; 
        int n = a.size();
        int m = b.size();
        if(m > n) {
            while(n!=m) {
                a = "0" + a;
                n++;
            }
        } else {
            while(m!=n) {
                b = "0" + b;
                m++;
            }
        }
        char carry = '0';
        for(int i=n-1; i>=0;i--) {
            if(a[i] == '1' and b[i]=='1' and carry == '0') {
                helper.push_back('0');
                carry = '1';
            } else if(a[i]=='1' and b[i]=='1' and carry == '1'){
                helper.push_back('1');
                carry = '1';
            }
            else if(a[i]=='1' and b[i]=='0' and carry == '1'){
                helper.push_back('0');
                carry = '1';
            } else if(a[i]=='0' and b[i]=='1' and carry == '1'){
                helper.push_back('0');
                carry = '1';
            }else if (a[i]=='0' and b[i]=='0' and carry == '0'){
                helper.push_back('0');
                carry = '0';
            }
            else {
                helper.push_back('1');
                carry = '0';
            }
        }
        string ans = "";
        ans = carry=='1' ? (carry + ans) : ans;
        for(int i = helper.size()-1;i>=0;i--) {
            ans += helper[i];
        }
        return ans;
    }
};
