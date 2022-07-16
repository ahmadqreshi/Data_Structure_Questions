//method 1 - by using bitwise operator
int convertToBinary(int n) {
    int ans = 0;
    int power = 1;
    while(n) {
        if(n&1) {
            ans += power;
        }
        power = power*10;   // 101 -> 10^2 + 10^1 + 10^0
        n = n>>1;
    }
    return ans;
}
