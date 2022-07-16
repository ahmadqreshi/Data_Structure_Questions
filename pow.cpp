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
