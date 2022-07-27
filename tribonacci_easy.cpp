/*
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
*/


// method 1 - by using 4 variables and swappping them after
class Solution {
public:
 int tribonacci(int n) {
    int a = 0;
    int b = 1;
    int c = 1;
    int d = 0;
    for(int i=3;i<=n;i++) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    if(n==0)
        return a;
    else if (n==1)
        return b;
    else if(n==2)
        return c;
    else
        return d;
    }
};
//method 2 :-  by using recursion
class Solution {
public:
    int tribonacci(int n) {
       if(n==0)
           return 0;
        else if(n>0 and n<=2)
            return 1;
        else 
            return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};
