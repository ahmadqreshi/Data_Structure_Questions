
#include <iostream>
using namespace std;
// number of bits in a number n will be atmost log(n)+1
//time complexity will be log(n)
int fastExponentiation(int a,int n) {
    int ans = 1;
    while(n) {
        if(n&1) { //checks for the last bit is 1
            ans *= a;
        }
        a = a*a;
        n = n>>1; //shift bits to right one by one
    }
    return ans;
}
int main()
{
    cout<<fastExponentiation(4,2);
    return 0;
}
