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
