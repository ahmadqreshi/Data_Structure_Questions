//tree recurion when more than one call are there
//time complexity - o(2^n)
//space complexity - o(n)
#include <iostream>
using namespace std;
int fib(int n) {
    if(n==0 or n==1){
        return n;
    }
    int fib1 = fib(n-1);
    int fib2 = fib(n-2);
    return fib1 + fib2;
}
int main()
{
    cout<<fib(6);
    return 0;
}

//method 2 - by using direct formula O(log n ) because of pow function has logn time complexity
class Solution {
public:
    int fib(int n) {
        double phi = (sqrt(5) + 1)/2;
        return round(pow(phi,n)/sqrt(5));
    }
};
