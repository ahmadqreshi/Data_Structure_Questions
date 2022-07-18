//Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long temp = abs(n);
        while(temp) {
            if(temp&1) {
                ans *= x;
            }
            x = x*x;
            temp = temp>>1;
        }
        return (n>0) ? ans : (1/ans);
    }
};
//method 2 - log(n)
#include <bits/stdc++.h>
using namespace std;
int fastPow(int m,int n) {
    if(n==0)
        return 1;
    int ans = fastPow(m,n/2);
    int subans = ans*ans;
    if(n&1)
     return m*subans;
    else 
        return subans;
}
int main()
{
    cout<<fastPow(2,4);

    return 0;
}
