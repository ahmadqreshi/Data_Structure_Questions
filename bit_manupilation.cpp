//count set bits (1s) in a number 
#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while(n) {
        count += (n&1);
        n = n>>1; // shift bits towards right hand
    }
    return count;
}
// check a number is even or not
bool checkEvenOdd(int n) {
    return (n&1) ? true : false; // (3&1) == 1
}
//check a number is power of 2 or not
bool checkPowerOf2(int n) {
    return ((n&n-1)==0) ? true : false; 
}
int main()
{
    int ans = countSetBits(11);
    cout<<"Number of 1s are : "<<ans<<endl;
    if(checkEvenOdd(3)) cout<<"Odd Number";
    else cout<<"Even Number";
    cout<<endl;
    if(checkPowerOf2(64)) cout<<"Power of 2";
    else cout<<"Not power of 2";
}


