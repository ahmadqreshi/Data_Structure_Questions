//Given an integer n, return the number of trailing zeroes in n!.

//long long int in c can store upto 10^18 digits only so brute force of this approach will give TLE

// so in order to solve this question in logarithmic time 
// just count number of 5s multiples in any number
/*
formula used :
for n = 100;
number of trailing zeroes = 100/5 + 100/5*5 + 100/5*5*5 until(100/5*5*5 > 0)
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int p = 5;
        while(n/p != 0) {
            ans += n/p;
            p = p*5;
        }
        return ans;
    }
};
